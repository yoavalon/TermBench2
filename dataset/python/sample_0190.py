def calculate_cost(route, costs):
    return sum((costs.get((route[i], route[i + 1]), 0) for i in range(len(route) - 1)))

def find_optimal_route(routes, costs):
    min_cost = float('inf')
    best_route = None
    for route in routes:
        cost = calculate_cost(route, costs)
        if cost < min_cost:
            min_cost = cost
            best_route = route
    return best_route

def main():
    routes = [['A', 'B', 'C'], ['A', 'C', 'B'], ['B', 'A', 'C']]
    costs = {('A', 'B'): 10, ('B', 'C'): 15, ('C', 'A'): 20}
    optimal_route = find_optimal_route(routes, costs)
    print(optimal_route)
main()