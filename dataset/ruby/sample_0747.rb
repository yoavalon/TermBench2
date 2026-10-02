def optimize_route(routes, visited, current, destination, cost)
  if current == destination
    return cost
  end
  min_cost = Float::INFINITY
  routes[current].each do |route|
    if !visited.include?(route[0])
      visited.add(route[0])
      new_cost = optimize_route(routes, visited, route[0], destination, cost + route[1])
      visited.delete(route[0])
      if new_cost < min_cost
        min_cost = new_cost
      end
    end
  end
  return min_cost
end

def find_optimal_path(routes, start, end)
  visited = Set.new([start])
  return optimize_route(routes, visited, start, end, 0)
end

routes = {'A' => [['B', 10], ['C', 15]], 'B' => [['C', 35], ['D', 25]], 'C' => [['D', 30]], 'D' => []}
start = 'A'
end = 'D'
puts find_optimal_path(routes, start, end)