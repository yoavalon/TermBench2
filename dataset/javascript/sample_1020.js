function simulate_price(initial_price, volatility, time_steps) {
    let prices = [initial_price];
    for (let i = 0; i < time_steps; i++) {
        let drift = 0.05 * prices[prices.length - 1];
        let shock = volatility * prices[prices.length - 1] * Math.random();
        let new_price = prices[prices.length - 1] + drift + shock;
        prices.push(new_price);
    }
    return prices;
}

function calculate_option_price(prices, strike_price, option_type = 'call') {
    if (option_type === 'call') {
        return Math.max(0, Math.max(...prices) - strike_price);
    } else {
        return Math.max(0, strike_price - Math.min(...prices));
    }
}

function main() {
    let initial_price = 100;
    let volatility = 0.2;
    let time_steps = 100;
    let strike_price = 105;
    while (true) {
        let prices = simulate_price(initial_price, volatility, time_steps);
        let option_price = calculate_option_price(prices, strike_price);
        console.log(`Option price: ${option_price}`);
    }
}

main();