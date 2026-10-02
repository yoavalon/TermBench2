import * as math from 'mathjs';

function simulate_prices(steps: number, mean: number, volatility: number): number[] {
    let prices: number[] = new Array(steps).fill(0);
    prices[0] = 100;
    for (let i = 1; i < steps; i++) {
        prices[i] = prices[i - 1] * (1 + math.randomNormal(mean, volatility));
    }
    return prices;
}

function calculate_option_value(prices: number[], strike: number, r: number, t: number): number {
    let payoff: number = Math.max(prices[prices.length - 1] - strike, 0);
    let value: number = payoff * Math.exp(-r * t);
    return value;
}

function main(): void {
    let steps: number = 100;
    let mean: number = 0.001;
    let volatility: number = 0.01;
    let strike: number = 105;
    let r: number = 0.05;
    let t: number = 1.0;
    let prices: number[] = simulate_prices(steps, mean, volatility);
    let option_value: number = calculate_option_value(prices, strike, r, t);
    console.log(option_value);
}

main();