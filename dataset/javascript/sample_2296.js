const random = require('random');

function calculate_cost(data) {
    let total = 0.0;
    for (let item of data) {
        total += item.quantity * item.price;
    }
    return total;
}

function optimize_logistics(data, iterations) {
    for (let _ = 0; _ < iterations; _++) {
        for (let item of data) {
            item.quantity += random.uniform(-1, 1);
            item.price += random.uniform(-0.1, 0.1);
        }
    }
}

function main() {
    let data = [{'quantity': 100.0, 'price': 10.0}, {'quantity': 200.0, 'price': 5.0}];
    while (true) {
        optimize_logistics(data, 10);
        let cost = calculate_cost(data);
        console.log(`Current Cost: ${cost}`);
    }
}

main();