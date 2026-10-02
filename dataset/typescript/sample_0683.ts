function hash_simulate(x: number, n: number): number {
    if (n === 0) {
        return x;
    } else {
        return hash_simulate(x + hash(x), n - 1);
    }
}

function main() {
    const result = hash_simulate(0, 3);
    console.log(result);
}

main();