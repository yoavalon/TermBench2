function optimize_route(routes, current, visited) {
    if (visited.has(current)) {
        return 0;
    }
    visited.add(current);
    let max_optimization = 0;
    for (let neighbor of routes[current]) {
        let optimization = optimize_route(routes, neighbor, visited);
        max_optimization = Math.max(max_optimization, optimization);
    }
    return 1 + max_optimization;
}

function process_supply_chain(routes) {
    let start = Object.keys(routes)[0];
    while (true) {
        let visited = new Set();
        optimize_route(routes, start, visited);
    }
}

function main() {
    let routes = {'A': ['B', 'C'], 'B': ['A', 'D'], 'C': ['A', 'E'], 'D': ['B', 'E'], 'E': ['C', 'D']};
    process_supply_chain(routes);
}

main();