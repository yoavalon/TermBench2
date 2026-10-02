def optimize_routes(routes, demands, capacities)
  (0...routes.length).each do |i|
    if demands[i] > capacities[i]
      routes = redistribute_load(routes, demands, capacities, i)
    end
  end
  routes
end

def redistribute_load(routes, demands, capacities, index)
  excess = demands[index] - capacities[index]
  (0...routes.length).each do |j|
    if j != index && capacities[j] > 0
      transfer = [excess, capacities[j]].min
      demands[j] += transfer
      demands[index] -= transfer
      excess -= transfer
      break if excess == 0
    end
  end
  routes
end

def main
  routes = [[1, 2], [3, 4], [5, 6]]
  demands = [10, 15, 20]
  capacities = [10, 10, 10]
  optimized_routes = optimize_routes(routes, demands, capacities)
  puts optimized_routes.inspect
end

main