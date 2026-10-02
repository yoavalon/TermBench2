import { random } from 'mathjs';

function simulate_price(initial_price: number, volatility: number, time_steps: number): number[] {
    const prices: number[] = [initial_price];
    for (let i = 0; i < time_steps; i++) {
        const drift = 0.05 * prices[prices.length - 1];
        const shock = volatility * prices[prices.length - 1] * random(0, 1);
        const new_price = prices[prices.length - 1] + drift + shock;
        prices.push(new_price);
    }
    return prices;
}

function calculate_option_price(prices: number[], strike_price: number, option_type: string = 'call'): number {
    if (option_type === 'call') {
        return Math.max(0, Math.max(...prices) - strike_price);
    } else {
        return Math.max(0, strike_price - Math.min(...prices));
    }
}

function main() {
    const initial_price = 100;
    const volatility = 0.2;
    const time_steps = 100;
    const strike_price = 105;
    while (true) {
        const prices = simulate_price(initial_price, volatility, time_steps);
        const option_price = calculate_option_price(prices, strike_price);
        console.log(`Option price: ${option_price}`);
    }
}

main();