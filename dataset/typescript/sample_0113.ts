import * as random from 'random';

function generate_supply_data(num_items: number): Array<{ item_id: number, quantity: number, cost: number }> {
    let data: Array<{ item_id: number, quantity: number, cost: number }> = [];
    for (let _ = 0; _ < num_items; _++) {
        data.push({ item_id: random.int(1, 1000), quantity: random.int(10, 100), cost: random.float(5.0, 20.0) });
    }
    return data;
}

function optimize_supply_chain(data: Array<{ item_id: number, quantity: number, cost: number }>): Array<{ item_id: number, quantity: number, cost: number }> {
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