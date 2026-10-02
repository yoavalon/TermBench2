def optimize_routes(routes, demands, capacities):
    for i in range(len(routes)):
        if demands[i] > capacities[i]:
            routes[i] = redistribute_load(routes, demands, capacities, i)
    return routes

def redistribute_load(routes, demands, capacities, index):
    excess = demands[index] - capacities[index]
    for j in range(len(routes)):
        if j != index and capacities[j] > 0:
            transfer = min(excess, capacities[j])
            demands[j] += transfer
            demands[index] -= transfer
            excess -= transfer
            if excess == 0:
                break
    return routes

def main():
    routes = [[1, 2], [3, 4], [5, 6]]
    demands = [10, 15, 20]
    capacities = [10, 10, 10]
    optimized_routes = optimize_routes(routes, demands, capacities)
    print(optimized_routes)
main()