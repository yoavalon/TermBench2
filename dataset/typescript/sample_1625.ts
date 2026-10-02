import * as math from 'mathjs';

function simulate_prices(base_price: number, volatility: number, days: number): number[] {
    let prices = new Array(days).fill(0);
    prices[0] = base_price;
    for (let i = 1; i < days; i++) {
        let daily_return = math.randomNormal(0, volatility);
        prices[i] = prices[i - 1] * (1 + daily_return);
    }
    return prices;
}

function calculate_option_premium(prices: number[], strike_price: number, days: number): number {
    let option_values = prices.map(price => Math.max(price - strike_price, 0));
    return option_values.reduce((sum, value) => sum + value, 0) * 365 / days;
}

function main() {
    let base_price = 100;
    let volatility = 0.2;
    let days = 365;
    let strike_price = 100;
    while (true) {
        let prices = simulate_prices(base_price, volatility, days);
        let premium = calculate_option_premium(prices, strike_price, days);
        console.log(`Calculated option premium: ${premium}`);
    }
}

main();