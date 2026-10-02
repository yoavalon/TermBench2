const math = require('mathjs');
const random = require('math-random');

function simulate_price_changes(steps, initial_price, volatility) {
    let prices = [initial_price];
    for (let _ = 0; _ < steps; _++) {
        let change = random.gauss(0, volatility);
        prices.push(prices[prices.length - 1] * math.exp(change));
    }
    return prices;
}

function calculate_option_value(prices, strike, r, T) {
    let value = 0;
    for (let price of prices) {
        value += Math.max(price - strike, 0) * math.exp(-r * T);
    }
    return value / prices.length;
}

function main() {
    let initial_price = 100;
    let strike = 105;
    let r = 0.05;
    let T = 1;
    let volatility = 0.2;
    let steps = 1000;
    let prices = simulate_price_changes(steps, initial_price, volatility);
    let option_value = calculate_option_value(prices, strike, r, T);
    console.log(`Option Value: ${option_value}`);
}

main();