def calculate_route_costs(routes):
    costs = []
    for route in routes:
        cost = sum(route)
        costs.append(cost)
    return costs

def optimize_routes(routes, budgets):
    optimized_routes = []
    for route, budget in zip(routes, budgets):
        if sum(route) <= budget:
            optimized_routes.append(route)
    return optimized_routes

def main():
    routes = [[10, 20, 30], [40, 50, 60], [70, 80, 90]]
    budgets = [150, 200, 250]
    costs = calculate_route_costs(routes)
    optimized_routes = optimize_routes(routes, budgets)
    print(optimized_routes)
main()