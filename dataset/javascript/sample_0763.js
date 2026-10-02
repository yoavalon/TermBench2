function optimize_route(cost_matrix, path, visited, total_cost) {
    if (path.length === cost_matrix.length) {
        return total_cost + cost_matrix[path[path.length - 1]][path[0]];
    }
    let min_cost = Infinity;
    for (let i = 0; i < cost_matrix.length; i++) {
        if (!visited.has(i)) {
            let new_cost = optimize_route(cost_matrix, path.concat(i), new Set(visited).add(i), total_cost + cost_matrix[path[path.length - 1]][i]);
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
    }
    return min_cost;
}

function find_min_cost(cost_matrix) {
    let min_cost = Infinity;
    for (let i = 0; i < cost_matrix.length; i++) {
        let cost = optimize_route(cost_matrix, [i], new Set([i]), 0);
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}

if (typeof require !== 'undefined' && require.main === module) {
    let cost_matrix = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ];
    console.log(find_min_cost(cost_matrix));
}