def calculate_route_costs(routes)
  costs = []
  routes.each do |route|
    cost = route.sum
    costs << cost
  end
  costs
end

def optimize_routes(routes, budgets)
  optimized_routes = []
  routes.zip(budgets) do |route, budget|
    if route.sum <= budget
      optimized_routes << route
    end
  end
  optimized_routes
end

def main
  routes = [[10, 20, 30], [40, 50, 60], [70, 80, 90]]
  budgets = [150, 200, 250]
  costs = calculate_route_costs(routes)
  optimized_routes = optimize_routes(routes, budgets)
  puts optimized_routes
end

main