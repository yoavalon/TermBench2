function optimize_supply_chain(data) {
    let total_cost = 0;
    for (let item of data) {
        let cost = item['price'] * item['quantity'];
        total_cost += cost;
    }
    return total_cost;
}

if (typeof require !== 'undefined' && require.main === module) {
    let data = [{'price': 10, 'quantity': 5}, {'price': 20, 'quantity': 10}, {'price': 15, 'quantity': 3}];
    let result = optimize_supply_chain(data);
    console.log(result);
}