def optimize_route(routes, demands):
    costs = []
    for r in routes:
        cost = sum((demands[i] * r[i] for i in range(len(demands))))
        costs.append(cost)
    return min(costs)

def update_demands(demands, adjustments):
    return [d + a for d, a in zip(demands, adjustments)]

def main():
    routes = [[2, 3, 1], [4, 1, 2], [3, 2, 3]]
    demands = [5, 10, 15]
    adjustments = [-1, 2, -3]
    updated_demands = update_demands(demands, adjustments)
    best_cost = optimize_route(routes, updated_demands)
    print(best_cost)
main()