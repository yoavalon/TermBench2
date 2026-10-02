function optimize_supply_chain(x: number, y: number): void {
    if (x > y) {
        optimize_supply_chain(x - 1, y);
    } else if (x < y) {
        optimize_supply_chain(x, y - 1);
    } else {
        optimize_supply_chain(x + 1, y + 1);
    }
}

optimize_supply_chain(1, 1);