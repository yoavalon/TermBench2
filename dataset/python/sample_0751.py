def optimize_route(cost_matrix, current_route, visited, total_cost):
    if len(current_route) == len(cost_matrix):
        return total_cost
    min_cost = float('inf')
    for i in range(len(cost_matrix)):
        if i not in visited:
            visited.add(i)
            cost = optimize_route(cost_matrix, current_route + [i], visited, total_cost + cost_matrix[current_route[-1]][i])
            visited.remove(i)
            if cost < min_cost:
                min_cost = cost
    return min_cost

def main():
    cost_matrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
    initial_route = [0]
    visited = set([0])
    result = optimize_route(cost_matrix, initial_route, visited, 0)
    print(result)
main()