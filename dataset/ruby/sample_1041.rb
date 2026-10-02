def optimize_route(routes, current_cost)
  if routes.empty?
    return current_cost
  end
  next_route = routes.shift
  new_cost = current_cost + next_route[1]
  optimize_route(routes, new_cost)
end

def process_logistics(data)
  if data.nil?
    return
  end
  routes = data['routes']
  total_cost = optimize_route(routes, 0)
  puts total_cost
  process_logistics(data)
end

data = {'routes' => [['A', 10], ['B', 20], ['C', 30]]}
process_logistics(data)