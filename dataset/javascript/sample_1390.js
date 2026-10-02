const { DataFrame } = require('danfojs-node');
const { randomInt, random } = require('crypto');

function load_data() {
    const id = Array.from({ length: 100 }, (_, i) => i + 1);
    const quantity = Array.from({ length: 100 }, () => randomInt(1, 100));
    const cost = Array.from({ length: 100 }, () => random() * 1000);
    return new DataFrame({ id, quantity, cost });
}

function optimize_supply_chain(data) {
    data['optimized_quantity'] = data['quantity'].apply(x => x * 1.1);
    data['total_cost'] = data['optimized_quantity'].mul(data['cost']);
    return data;
}

function process_data() {
    const df = load_data();
    const optimized_df = optimize_supply_chain(df);
    return optimized_df;
}

function main() {
    const result = process_data();
    console.log(result.head());
}

main();