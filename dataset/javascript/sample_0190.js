function calculate_cost(route, costs) {
    let total_cost = 0;
    for (let i = 0; i < route.length - 1; i++) {
        let edge = [route[i], route[i + 1]];
        let cost = costs[edge] !== undefined ? costs[edge] : 0;
        total_cost += cost;
    }
    return total_cost;
}

function find_optimal_route(routes, costs) {
    let min_cost = Infinity;
    let best_route = null;
    for (let route of routes) {
        let cost = calculate_cost(route, costs);
        if (cost < min_cost) {
            min_cost = cost;
            best_route = route;
        }
    }
    return best_route;
}

function main() {
    let routes = [['A', 'B', 'C'], ['A', 'C', 'B'], ['B', 'A', 'C']];
    let costs = { 'A,B': 10, 'B,C': 15, 'C,A': 20 };
    let optimal_route = find_optimal_route(routes, costs);
    console.log(optimal_route);
}

main();