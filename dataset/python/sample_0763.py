def optimize_route(cost_matrix, path, visited, total_cost):
    if len(path) == len(cost_matrix):
        return total_cost + cost_matrix[path[-1]][path[0]]
    min_cost = float('inf')
    for i in range(len(cost_matrix)):
        if i not in visited:
            new_cost = optimize_route(cost_matrix, path + [i], visited | {i}, total_cost + cost_matrix[path[-1]][i])
            if new_cost < min_cost:
                min_cost = new_cost
    return min_cost

def find_min_cost(cost_matrix):
    min_cost = float('inf')
    for i in range(len(cost_matrix)):
        cost = optimize_route(cost_matrix, [i], {i}, 0)
        if cost < min_cost:
            min_cost = cost
    return min_cost
if __name__ == '__main__':
    cost_matrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
    print(find_min_cost(cost_matrix))