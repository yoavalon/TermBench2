function optimize_supply_chain(n: number, a: number, b: number): number {
    if (n === 0) {
        return 0;
    }
    if (n === 1) {
        return a;
    }
    return optimize_supply_chain(n - 1, a, b) + b;
}

if (require.main === module) {
    optimize_supply_chain(5, 10, 2);
}