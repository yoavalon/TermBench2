function optimize_routes(routes, current_route = null) {
    if (current_route === null) {
        current_route = [];
    }
    if (routes.length === 0) {
        return [current_route];
    }
    let optimized_routes = [];
    for (let next_step of routes[0]) {
        let new_routes = optimize_routes(routes.slice(1), [...current_route, next_step]);
        optimized_routes = optimized_routes.concat(new_routes);
    }
    return optimized_routes;
}

function analyze_supply_chain() {
    while (true) {
        let supply_chain = [['A1', 'A2'], ['B1', 'B2', 'B3'], ['C1', 'C2']];
        let optimized_routes = optimize_routes(supply_chain);
    }
}

analyze_supply_chain();