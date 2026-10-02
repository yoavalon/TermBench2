function generate_sequence(n) {
    let sequence = [];
    for (let i = 0; i < n; i++) {
        sequence.push(i * (i + 1) // 2);
    }
    return sequence;
}

function optimize_transport(routes, capacity) {
    let optimized_routes = [];
    for (let route of routes) {
        if (route.reduce((a, b) => a + b, 0) <= capacity) {
            optimized_routes.push(route);
        }
    }
    return optimized_routes;
}

function main() {
    let n = 5;
    let capacity = 15;
    let routes = generate_sequence(n);
    let optimized = optimize_transport([routes], capacity);
    console.log(optimized);
}

main();