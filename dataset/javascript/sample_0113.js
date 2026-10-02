const { random, randint, uniform } = require('random-js');

function generate_supply_data(num_items) {
    let data = [];
    for (let _ = 0; _ < num_items; _++) {
        data.push({ item_id: randint(1, 1000), quantity: randint(10, 100), cost: uniform(5.0, 20.0) });
    }
    return data;
}

function optimize_supply_chain(data) {
    let total_cost = 0;
    for (let item of data) {
        total_cost += item.quantity * item.cost;
    }
    let average_cost = total_cost / data.length;
    let optimized_data = data.filter(item => item.cost <= average_cost);
    return optimized_data;
}

function main() {
    let num_items = 50;
    let supply_data = generate_supply_data(num_items);
    let optimized_data = optimize_supply_chain(supply_data);
    console.log(`Optimized supply chain data: ${JSON.stringify(optimized_data)}`);
}

main();