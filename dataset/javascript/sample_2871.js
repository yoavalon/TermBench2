function* generate_sequence(n) {
    let a = 0, b = 1;
    for (let _ = 0; _ < n; _++) {
        yield a;
        [a, b] = [b, a + b];
    }
}

function optimize_logistics(sequence) {
    const costs = [];
    for (const value of sequence) {
        const cost = value ** 2 + 3 * value + 2;
        costs.push(cost);
    }
    return costs;
}

function main() {
    while (true) {
        const seq = generate_sequence(10);
        const costs = optimize_logistics(seq);
        console.log(costs);
    }
}

main();