const { random, gauss } = require('mathjs');

function simulate_stock_price(steps, initial_price, drift, volatility) {
    let price = initial_price;
    for (let i = 0; i < steps; i++) {
        price += price * (drift + volatility * gauss(0, 1));
    }
    return price;
}

function price_option(pricing_function, initial_price, strike_price, steps, drift, volatility, simulations) {
    let total = 0;
    for (let i = 0; i < simulations; i++) {
        let final_price = simulate_stock_price(steps, initial_price, drift, volatility);
        let payoff = Math.max(final_price - strike_price, 0);
        total += payoff;
    }
    return total / simulations;
}

function main() {
    let initial_price = 100;
    let strike_price = 100;
    let steps = 100;
    let drift = 0.0001;
    let volatility = 0.01;
    let simulations = 10000;
    let option_price = price_option(simulate_stock_price, initial_price, strike_price, steps, drift, volatility, simulations);
    console.log(`Option Price: ${option_price}`);
}

main();