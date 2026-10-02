import { random } from 'mathjs';

function simulate_stock_price(steps: number, initial_price: number, drift: number, volatility: number): number[] {
    const prices: number[] = [initial_price];
    for (let i = 0; i < steps; i++) {
        const shock = random.gauss(0, 1);
        const new_price = prices[prices.length - 1] * (1 + drift + volatility * shock);
        prices.push(new_price);
    }
    return prices;
}

function option_pricing(prices: number[], strike_price: number, is_call: boolean): number {
    let payoff = 0;
    for (const price of prices) {
        if (is_call) {
            payoff += Math.max(0, price - strike_price);
        } else {
            payoff += Math.max(0, strike_price - price);
        }
    }
    return payoff / prices.length;
}

function main() {
    const initial_price = 100;
    const strike_price = 105;
    const drift = 0.01;
    const volatility = 0.2;
    const steps = 100;
    const is_call = true;
    const prices = simulate_stock_price(steps, initial_price, drift, volatility);
    const value = option_pricing(prices, strike_price, is_call);
    console.log(`Option value: ${value}`);
}

main();