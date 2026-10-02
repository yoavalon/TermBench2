function optimize_supply_chain(data) {
    let total_cost = 0.0;
    for (let item of data) {
        total_cost += item['quantity'] * item['price'];
    }
    return Math.round(total_cost * 100) / 100;
}

function main() {
    let data = [{'quantity': 150.75, 'price': 2.34}, {'quantity': 200.5, 'price': 1.8}, {'quantity': 120.25, 'price': 3.15}];
    let result = optimize_supply_chain(data);
    console.log(result);
}

main();