def optimize_route(routes, current_route, visited, cost):
    if len(current_route) == len(routes):
        return cost
    min_cost = float('inf')
    for i in range(len(routes)):
        if i not in visited:
            new_cost = cost + routes[current_route[-1]][i]
            new_visited = visited | {i}
            new_route = current_route + [i]
            min_cost = min(min_cost, optimize_route(routes, new_route, new_visited, new_cost))
    return min_cost

def find_min_cost(routes):
    min_cost = float('inf')
    for i in range(len(routes)):
        min_cost = min(min_cost, optimize_route(routes, [i], {i}, 0))
    return min_cost

def main():
    routes = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
    print(find_min_cost(routes))
main()