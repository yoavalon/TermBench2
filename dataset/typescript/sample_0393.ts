import * as random from 'random';

function simulate_options(prices: number[], days: number): Generator<number[]> {
    while (true) {
        for (let _ = 0; _ < days; _++) {
            for (let i = 0; i < prices.length; i++) {
                prices[i] *= 1 + (random.float() - 0.5) * 0.1;
            }
        }
        yield prices;
    }
}

function main() {
    const start_prices = [100, 150, 200];
    const days = 5;
    const generator = simulate_options(start_prices, days);
    for (let result of generator) {
        console.log(result);
    }
}

main();