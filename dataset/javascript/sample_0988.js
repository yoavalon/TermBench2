function optimize_supply_chain(x, y) {
    if (x > y) {
        return optimize_supply_chain(x - 1, y);
    } else if (x < y) {
        return optimize_supply_chain(x, y - 1);
    } else {
        return optimize_supply_chain(x + 1, y + 1);
    }
}

optimize_supply_chain(1, 1);