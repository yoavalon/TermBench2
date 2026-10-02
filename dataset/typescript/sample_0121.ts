import * as random from 'mathjs';

function simulate_stock_price(start: number, volatility: number, days: number): number[] {
    const prices = [start];
    for (let _ = 0; _ < days; _++) {
        const price_change = random.gauss(0, volatility);
        const new_price = prices[prices.length - 1] * (1 + price_change);
        prices.push(new_price);
    }
    return prices;
}

function calculate_option_value(prices: number[], strike: number, days: number, risk_free_rate: number): number {
    const final_price = prices[prices.length - 1];
    const payoff = Math.max(final_price - strike, 0);
    return payoff / Math.pow(1 + risk_free_rate, days);
}

function main() {
    const start_price = 100;
    const volatility = 0.2;
    const strike_price = 105;
    const days = 30;
    const risk_free_rate = 0.05;
    const iterations = 1000;
    let total_value = 0;
    for (let _ = 0; _ < iterations; _++) {
        const prices = simulate_stock_price(start_price, volatility, days);
        const option_value = calculate_option_value(prices, strike_price, days, risk_free_rate);
        total_value += option_value;
    }
    const average_value = total_value / iterations;
    console.log(average_value);
}

main();