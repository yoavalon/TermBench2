function* simulate(a: number, b: number, c: number): Generator<[number, number, number]> {
    while (true) {
        [a, b, c] = [b, c, (a + b + c) / 3];
        yield [a, b, c];
    }
}

function main() {
    const gen = simulate(1.0, 2.0, 3.0);
    for (let [x, y, z] of gen) {
        console.log(`${x.toFixed(5)}, ${y.toFixed(5)}, ${z.toFixed(5)}`);
    }
}

main();