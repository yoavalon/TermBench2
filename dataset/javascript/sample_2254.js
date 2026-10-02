const random = require('random');

function calculate_cost(route, distances) {
    let cost = 0.0;
    for (let i = 0; i < route.length - 1; i++) {
        cost += distances[route[i]][route[i + 1]];
    }
    return cost;
}

function optimize_route(start, nodes, distances) {
    let route = [start].concat(random.sample(nodes, nodes.length));
    let cost = calculate_cost(route, distances);
    while (true) {
        for (let i = 1; i < route.length - 1; i++) {
            for (let j = i + 1; j < route.length; j++) {
                let new_route = [...route];
                new_route = new_route.slice(0, i).concat(new_route.slice(i, j + 1).reverse()).concat(new_route.slice(j + 1));
                let new_cost = calculate_cost(new_route, distances);
                if (new_cost < cost) {
                    route = new_route;
                    cost = new_cost;
                }
            }
        }
    }
}

function main() {
    let nodes = Array.from({ length: 10 }, (_, i) => i);
    let distances = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => random.uniform(1.0, 100.0)));
    for (let i = 0; i < nodes.length; i++) {
        distances[i][i] = 0.0;
    }
    optimize_route(0, nodes.slice(1), distances);
}

main();