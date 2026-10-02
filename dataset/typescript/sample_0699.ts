function simulate(x: number, y: number, n: number): [number, number] {
    if (n === 0) {
        return [x, y];
    } else {
        return simulate(x + y, y, n - 1);
    }
}

function main() {
    const result = simulate(1, 1, 5);
    console.log(result);
}

main();