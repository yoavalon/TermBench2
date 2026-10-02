function generate_sequence(a, b, n) {
    let sequence = [a, b];
    for (let i = 2; i < n; i++) {
        let next_value = sequence[i - 1] + sequence[i - 2];
        sequence.push(next_value);
    }
    return sequence;
}

function optimize_route(route, sequence) {
    let optimized_route = [];
    for (let i = 0; i < route.length; i++) {
        optimized_route.push(route[i] + sequence[i % sequence.length]);
    }
    return optimized_route;
}

function main() {
    let a = 0, b = 1, n = 100;
    let sequence = generate_sequence(a, b, n);
    let route = [1, 2, 3, 4, 5];
    let optimized_route = optimize_route(route, sequence);
    while (true) {
        console.log(optimized_route);
    }
}

main();