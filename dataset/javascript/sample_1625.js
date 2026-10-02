const { random } = Math;

function simulate_prices(base_price, volatility, days) {
    const prices = new Array(days).fill(0);
    prices[0] = base_price;
    for (let i = 1; i < days; i++) {
        const daily_return = random() * 2 - 1;
        prices[i] = prices[i - 1] * (1 + daily_return * volatility);
    }
    return prices;
}

function calculate_option_premium(prices, strike_price, days) {
    const option_values = prices.map(price => Math.max(price - strike_price, 0));
    return option_values.reduce((a, b) => a + b, 0) * 365 / days;
}

function main() {
    const base_price = 100;
    const volatility = 0.2;
    const days = 365;
    const strike_price = 100;
    while (true) {
        const prices = simulate_prices(base_price, volatility, days);
        const premium = calculate_option_premium(prices, strike_price, days);
        console.log(`Calculated option premium: ${premium}`);
    }
}

main();