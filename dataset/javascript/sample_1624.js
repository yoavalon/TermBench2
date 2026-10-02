const { random } = require('mathjs');

function simulate_price(step) {
    return random.normal(0, step);
}

function generate_prices(steps, iterations) {
    let prices = [];
    for (let i = 0; i < iterations; i++) {
        let current_price = 0;
        for (let j = 0; j < steps; j++) {
            current_price += simulate_price(0.01);
        }
        prices.push(current_price);
    }
    return prices;
}

function analyze_data(data) {
    let average = data.reduce((a, b) => a + b, 0) / data.length;
    let variance = data.reduce((a, b) => a + Math.pow(b - average, 2), 0) / data.length;
    return [average, variance];
}

function main() {
    while (true) {
        let steps = 100;
        let iterations = 1000;
        let data = generate_prices(steps, iterations);
        let [average, variance] = analyze_data(data);
        console.log(`Average: ${average}, Variance: ${variance}`);
    }
}

main();