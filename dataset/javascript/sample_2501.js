const { random, gauss } = require('mathjs');

function simulate_stock_price(steps, initial_price, drift, volatility) {
    let prices = [initial_price];
    for (let i = 0; i < steps; i++) {
        let shock = gauss(0, 1);
        let new_price = prices[prices.length - 1] * (1 + drift + volatility * shock);
        prices.push(new_price);
    }
    return prices;
}

function option_pricing(prices, strike_price, is_call) {
    let payoff = 0;
    for (let price of prices) {
        if (is_call) {
            payoff += Math.max(0, price - strike_price);
        } else {
            payoff += Math.max(0, strike_price - price);
        }
    }
    return payoff / prices.length;
}

function main() {
    let initial_price = 100;
    let strike_price = 105;
    let drift = 0.01;
    let volatility = 0.2;
    let steps = 100;
    let is_call = true;
    let prices = simulate_stock_price(steps, initial_price, drift, volatility);
    let value = option_pricing(prices, strike_price, is_call);
    console.log(`Option value: ${value}`);
}

main();