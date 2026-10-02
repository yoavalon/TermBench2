function simulate_stock_price(days, initial_price, volatility) {
    let price = initial_price;
    let prices = [price];
    for (let i = 0; i < days; i++) {
        price *= 1 + volatility * Math.random();
        prices.push(price);
    }
    return prices;
}

function calculate_option_value(prices, strike_price, days, risk_free_rate) {
    let final_price = prices[prices.length - 1];
    let payoff = Math.max(final_price - strike_price, 0);
    let discount_factor = 1 / Math.pow(1 + risk_free_rate, days);
    return payoff * discount_factor;
}

function main() {
    let days = 30;
    let initial_price = 100;
    let volatility = 0.2;
    let strike_price = 105;
    let risk_free_rate = 0.05;
    let prices = simulate_stock_price(days, initial_price, volatility);
    let option_value = calculate_option_value(prices, strike_price, days, risk_free_rate);
    console.log(`Option value: ${option_value}`);
}

main();