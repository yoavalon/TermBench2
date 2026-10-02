def optimize_route(routes, current_route, visited, cost)
  if current_route.length == routes.length
    return cost
  end
  min_cost = Float::INFINITY
  (0...routes.length).each do |i|
    unless visited.include?(i)
      new_cost = cost + routes[current_route.last][i]
      new_visited = visited | [i]
      new_route = current_route + [i]
      min_cost = [min_cost, optimize_route(routes, new_route, new_visited, new_cost)].min
    end
  end
  min_cost
end

def find_min_cost(routes)
  min_cost = Float::INFINITY
  (0...routes.length).each do |i|
    min_cost = [min_cost, optimize_route(routes, [i], [i], 0)].min
  end
  min_cost
end

def main
  routes = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
  puts find_min_cost(routes)
end

main