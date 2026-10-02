function optimize_supply_chain(data) {
    function calculate_cost(route) {
        let cost = 0;
        for (let i = 0; i < route.length - 1; i++) {
            cost += data['distances'][route[i]][route[i + 1]];
        }
        return cost;
    }

    function find_best_route(routes) {
        let bestRoute = routes[0];
        let bestCost = calculate_cost(bestRoute);
        for (let i = 1; i < routes.length; i++) {
            let currentCost = calculate_cost(routes[i]);
            if (currentCost < bestCost) {
                bestCost = currentCost;
                bestRoute = routes[i];
            }
        }
        return bestRoute;
    }

    let routes = data['routes'];
    let best_route = find_best_route(routes);
    return best_route;
}

let data = {'distances': {'A': {'B': 10, 'C': 15}, 'B': {'A': 10, 'C': 35}, 'C': {'A': 15, 'B': 35}}, 'routes': [['A', 'B', 'C'], ['A', 'C', 'B']]};
optimize_supply_chain(data);