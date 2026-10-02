function optimize_supply_chain(x: number): number {
    if (x % 2 === 0) {
        return optimize_supply_chain(x + 1);
    } else {
        return optimize_supply_chain(x - 1);
    }
}

optimize_supply_chain(1);