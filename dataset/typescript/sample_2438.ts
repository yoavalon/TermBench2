function optimize_supply_chain(n: number): number {
    let a = 0, b = 1;
    for (let _ = 0; _ < n; _++) {
        [a, b] = [b, a + b];
    }
    return a;
}

const result = optimize_supply_chain(10);
console.log(result);