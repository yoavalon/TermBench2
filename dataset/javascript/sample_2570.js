function calculate_optimal_routes(distance_matrix, max_routes) {
    let num_locations = distance_matrix.length;
    let routes = [];
    for (let i = 0; i < num_locations; i++) {
        for (let j = i + 1; j < num_locations; j++) {
            routes.push([i, j, distance_matrix[i][j]]);
        }
    }
    routes.sort((a, b) => a[2] - b[2]);
    let optimal_routes = [];
    let selected_pairs = new Set();
    for (let route of routes) {
        if (!selected_pairs.has(route[0]) && !selected_pairs.has(route[1])) {
            optimal_routes.push(route);
            selected_pairs.add(route[0]);
            selected_pairs.add(route[1]);
            if (optimal_routes.length === max_routes) {
                break;
            }
        }
    }
    return optimal_routes;
}

function main() {
    let distance_matrix = [[0, 10, 15, 20], [10, 0, 35, 25], [15, 35, 0, 30], [20, 25, 30, 0]];
    let max_routes = 2;
    let result = calculate_optimal_routes(distance_matrix, max_routes);
    console.log(result);
}

main();