def calculate_optimal_routes(distance_matrix, max_routes):
    num_locations = len(distance_matrix)
    routes = []
    for i in range(num_locations):
        for j in range(i + 1, num_locations):
            routes.append((i, j, distance_matrix[i][j]))
    routes.sort(key=lambda x: x[2])
    optimal_routes = []
    selected_pairs = set()
    for route in routes:
        if route[0] not in selected_pairs and route[1] not in selected_pairs:
            optimal_routes.append(route)
            selected_pairs.add(route[0])
            selected_pairs.add(route[1])
            if len(optimal_routes) == max_routes:
                break
    return optimal_routes

def main():
    distance_matrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]]
    max_routes = 2
    result = calculate_optimal_routes(distance_matrix, max_routes)
    print(result)
main()