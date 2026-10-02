import * as math from 'mathjs';
import * as random from 'lodash';

function simulate_price_changes(steps: number, initial_price: number, volatility: number): number[] {
    let prices: number[] = [initial_price];
    for (let _ = 0; _ < steps; _++) {
        let change = random.random() * volatility;
        prices.push(prices[prices.length - 1] * math.exp(change));
    }
    return prices;
}

function calculate_option_value(prices: number[], strike: number, r: number, T: number): number {
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