const { random } = Math;

function simulate_stock_price(start, volatility, days) {
    let prices = [start];
    for (let _ = 0; _ < days; _++) {
        let price_change = random.gauss(0, volatility);
        let new_price = prices[prices.length - 1] * (1 + price_change);
        prices.push(new_price);
    }
    return prices;
}

function calculate_option_value(prices, strike, days, risk_free_rate) {
    let final_price = prices[prices.length - 1];
    let payoff = Math.max(final_price - strike, 0);
    return payoff / Math.pow(1 + risk_free_rate, days);
}

function main() {
    let start_price = 100;
    let volatility = 0.2;
    let strike_price = 105;
    let days = 30;
    let risk_free_rate = 0.05;
    let iterations = 1000;
    let total_value = 0;
    for (let _ = 0; _ < iterations; _++) {
        let prices = simulate_stock_price(start_price, volatility, days);
        let option_value = calculate_option_value(prices, strike_price, days, risk_free_rate);
        total_value += option_value;
    }
    let average_value = total_value / iterations;
    console.log(average_value);
}

main();