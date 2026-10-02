def calculate_cost(route, costs)
  route.each_with_index.reduce(0) do |sum, (node, i)|
    sum + (costs[[node, route[i + 1]]] || 0)
  end
end

def find_optimal_route(routes, costs)
  min_cost = Float::INFINITY
  best_route = nil
  routes.each do |route|
    cost = calculate_cost(route, costs)
    if cost < min_cost
      min_cost = cost
      best_route = route
    end
  end
  best_route
end

def main
  routes = [['A', 'B', 'C'], ['A', 'C', 'B'], ['B', 'A', 'C']]
  costs = {['A', 'B'] => 10, ['B', 'C'] => 15, ['C', 'A'] => 20}
  optimal_route = find_optimal_route(routes, costs)
  puts optimal_route
end

main