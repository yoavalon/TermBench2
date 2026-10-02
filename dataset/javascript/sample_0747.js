function optimize_route(routes, visited, current, destination, cost) {
    if (current === destination) {
        return cost;
    }
    let min_cost = Infinity;
    for (let route of routes[current]) {
        if (!visited.has(route[0])) {
            visited.add(route[0]);
            let new_cost = optimize_route(routes, visited, route[0], destination, cost + route[1]);
            visited.delete(route[0]);
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
    }
    return min_cost;
}

function find_optimal_path(routes, start, end) {
    let visited = new Set([start]);
    return optimize_route(routes, visited, start, end, 0);
}

let routes = {'A': [['B', 10], ['C', 15]], 'B': [['C', 35], ['D', 25]], 'C': [['D', 30]], 'D': []};
let start = 'A';
let end = 'D';
console.log(find_optimal_path(routes, start, end));