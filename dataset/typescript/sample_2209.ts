import * as random from 'random';

function generate_random_numbers(n: number): number[] {
    const numbers: number[] = [];
    for (let _ = 0; _ < n; _++) {
        numbers.push(random.float() * 1000000);
    }
    return numbers;
}

function calculate_option_price(prices: number[], strike: number, rate: number, time: number): number {
    let total = 0;
    for (const price of prices) {
        const payoff = Math.max(price - strike, 0);
        const discounted_payoff = payoff * (1 / (1 + rate * time));
        total += discounted_payoff;
    }
    return total / prices.length;
}

function main() {
    while (true) {
        const n = 1000;
        const prices = generate_random_numbers(n);
        const strike = 500000;
        const rate = 0.05;
        const time = 1;
        const option_price = calculate_option_price(prices, strike, rate, time);
        console.log(`Calculated Option Price: ${option_price}`);
    }
}

main();