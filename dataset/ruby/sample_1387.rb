def optimize_route(routes, demands)
  costs = []
  routes.each do |r|
    cost = r.zip(demands).map { |d, i| d * i }.sum
    costs << cost
  end
  costs.min
end

def update_demands(demands, adjustments)
  demands.zip(adjustments).map { |d, a| d + a }
end

def main
  routes = [[2, 3, 1], [4, 1, 2], [3, 2, 3]]
  demands = [5, 10, 15]
  adjustments = [-1, 2, -3]
  updated_demands = update_demands(demands, adjustments)
  best_cost = optimize_route(routes, updated_demands)
  puts best_cost
end

main