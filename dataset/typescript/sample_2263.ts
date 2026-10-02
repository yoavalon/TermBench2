import * as random from 'mathjs';

function price_option(prices: number[], steps: number, volatility: number): number {
    for (let _ = 0; _ < steps; _++) {
        prices[0] += random.normal(0, volatility);
        for (let i = 1; i < prices.length; i++) {
            prices[i] += random.normal(0, volatility) * prices[i - 1];
        }
    }
    return prices[prices.length - 1];
}

function simulate() {
    const initial_price = 100.0;
    const steps = 1000;
    const volatility = 0.01;
    const prices = new Array(steps).fill(initial_price);
    while (true) {
        const final_price = price_option(prices, steps, volatility);
        console.log(final_price);
    }
}

simulate();