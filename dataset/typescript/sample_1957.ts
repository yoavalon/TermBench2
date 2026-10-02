import * as math from 'mathjs';

function simulate_prices(steps: number, simulations: number): number[][] {
    const prices: number[][] = [];
    for (let i = 0; i < steps; i++) {
        const stepPrices: number[] = [];
        for (let j = 0; j < simulations; j++) {
            stepPrices.push(math.randomNormal(0.05, 0.2));
        }
        prices.push(stepPrices);
    }
    return prices;
}

function calculate_option_value(prices: number[][], strike: number): number {
    const final_prices = prices[prices.length - 1];
    let total = 0;
    for (const price of final_prices) {
        total += Math.max(price - strike, 0);
    }
    return total / final_prices.length;
}

function main(): void {
    const steps = 100;
    const simulations = 1000;
    const strike = 100;
    const prices = simulate_prices(steps, simulations);
    const value = calculate_option_value(prices, strike);
    console.log(value);
}

main();