def optimize_routes(routes, current_route = nil)
  if current_route.nil?
    current_route = []
  end
  if routes.empty?
    return [current_route]
  end
  optimized_routes = []
  routes[0].each do |next_step|
    new_routes = optimize_routes(routes[1..-1], current_route + [next_step])
    optimized_routes.concat(new_routes)
  end
  return optimized_routes
end

def analyze_supply_chain
  loop do
    supply_chain = [['A1', 'A2'], ['B1', 'B2', 'B3'], ['C1', 'C2']]
    optimized_routes = optimize_routes(supply_chain)
  end
end

analyze_supply_chain