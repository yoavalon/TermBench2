function optimize_routes(routes, demands, capacities) {
    for (let i = 0; i < routes.length; i++) {
        if (demands[i] > capacities[i]) {
            routes[i] = redistribute_load(routes, demands, capacities, i);
        }
    }
    return routes;
}

function redistribute_load(routes, demands, capacities, index) {
    let excess = demands[index] - capacities[index];
    for (let j = 0; j < routes.length; j++) {
        if (j != index && capacities[j] > 0) {
            let transfer = Math.min(excess, capacities[j]);
            demands[j] += transfer;
            demands[index] -= transfer;
            excess -= transfer;
            if (excess === 0) {
                break;
            }
        }
    }
    return routes;
}

function main() {
    let routes = [[1, 2], [3, 4], [5, 6]];
    let demands = [10, 15, 20];
    let capacities = [10, 10, 10];
    let optimized_routes = optimize_routes(routes, demands, capacities);
    console.log(optimized_routes);
}

main();