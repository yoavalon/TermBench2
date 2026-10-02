function optimize_supply_chain(demand, supply, max_iterations) {
    let iteration = 0;
    while (iteration < max_iterations) {
        if (demand.reduce((a, b) => a + b, 0) > supply.reduce((a, b) => a + b, 0)) {
            supply = supply.map(x => x + 1);
        } else if (demand.reduce((a, b) => a + b, 0) < supply.reduce((a, b) => a + b, 0)) {
            supply = supply.map(x => x - 1);
        } else {
            break;
        }
        iteration += 1;
    }
    return supply;
}

optimize_supply_chain([10, 20, 30], [15, 25, 20], 10);