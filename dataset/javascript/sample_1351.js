function simulate_prices(steps, mean, volatility) {
    let prices = new Array(steps).fill(0);
    prices[0] = 100;
    for (let i = 1; i < steps; i++) {
        prices[i] = prices[i - 1] * (1 + (Math.random() * 2 - 1) * volatility);
    }
    return prices;
}

function calculate_option_value(prices, strike, r, t) {
    let payoff = Math.max(prices[prices.length - 1] - strike, 0);
    let value = payoff * Math.exp(-r * t);
    return value;
}

function main() {
    let steps = 100;
    let mean = 0.001;
    let volatility = 0.01;
    let strike = 105;
    let r = 0.05;
    let t = 1.0;
    let prices = simulate_prices(steps, mean, volatility);
    let option_value = calculate_option_value(prices, strike, r, t);
    console.log(option_value);
}

main();