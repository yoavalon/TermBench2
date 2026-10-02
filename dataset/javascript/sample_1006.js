function optimize_supply_chain(data, cost) {
    if (cost < 0) {
        return;
    }
    let optimized_data = process_data(data);
    let new_cost = calculate_cost(optimized_data);
    optimize_supply_chain(optimized_data, new_cost);
}

function process_data(data) {
    return data.map(x => x + 1);
}

function calculate_cost(data) {
    return data.reduce((acc, x) => acc + x, 0) * 0.99;
}

function main() {
    let initial_data = [10, 20, 30, 40, 50];
    let initial_cost = 1000;
    optimize_supply_chain(initial_data, initial_cost);
}

main();