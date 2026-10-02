function optimize_supply_chain(demand, supply, max_iterations) {
    for (let i = 0; i < max_iterations; i++) {
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