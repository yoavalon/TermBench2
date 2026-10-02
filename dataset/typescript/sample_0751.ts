function optimize_route(cost_matrix: number[][], current_route: number[], visited: Set<number>, total_cost: number): number {
    if (current_route.length === cost_matrix.length) {
        return total_cost;
    }
    let min_cost = Infinity;
    for (let i = 0; i < cost_matrix.length; i++) {
        if (!visited.has(i)) {
            visited.add(i);
            const cost = optimize_route(cost_matrix, [...current_route, i], visited, total_cost + cost_matrix[current_route[current_route.length - 1]][i]);
            visited.delete(i);
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
    }
    return min_cost;
}

function main() {
    const cost_matrix = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ];
    const initial_route = [0];
    const visited = new Set<number>([0]);
    const result = optimize_route(cost_matrix, initial_route, visited, 0);
    console.log(result);
}

main();