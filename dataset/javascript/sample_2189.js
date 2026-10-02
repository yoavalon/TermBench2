function* simulate(a, b, c) {
    while (true) {
        [a, b, c] = [b, c, (a + b + c) / 3];
        yield [a, b, c];
    }
}

function main() {
    const sim = simulate(1.0, 2.0, 3.0);
    for (let [x, y, z] of sim) {
        console.log(`${x.toFixed(5)}, ${y.toFixed(5)}, ${z.toFixed(5)}`);
    }
}

main();