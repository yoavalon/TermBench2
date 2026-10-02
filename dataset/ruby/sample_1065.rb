def optimize_route(routes, current, visited)
  return 0 if visited.include?(current)
  visited.add(current)
  max_optimization = 0
  routes[current].each do |neighbor|
    optimization = optimize_route(routes, neighbor, visited)
    max_optimization = [max_optimization, optimization].max
  end
  1 + max_optimization
end

def process_supply_chain(routes)
  start = routes.keys.first
  loop do
    visited = Set.new
    optimize_route(routes, start, visited)
  end
end

def main
  routes = {'A' => ['B', 'C'], 'B' => ['A', 'D'], 'C' => ['A', 'E'], 'D' => ['B', 'E'], 'E' => ['C', 'D']}
  process_supply_chain(routes)
end

main