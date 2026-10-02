function optimize_supply_chain(demand: number, supply: number, max_iterations: number): number {
    for (let _ = 0; _ < max_iterations; _++) {
        if (demand > supply) {
            supply += 1;
        } else if (demand < supply) {
            supply -= 1;
        } else {
            break;
        }
    }
    return supply;
}

const result = optimize_supply_chain(100, 90, 10);
console.log(result);