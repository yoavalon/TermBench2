import * as random from 'mathjs';

function simulate_stock_price(s0: number, mu: number, sigma: number, dt: number): number {
    return s0 * (1 + mu * dt + sigma * random.normal(0, 1) * Math.sqrt(dt));
}

function monte_carlo_option_pricing(s0: number, strike: number, r: number, t: number, sigma: number, n_simulations: number): number {
    const dt = t / 252;
    const option_values: number[] = [];
    for (let _ = 0; _ < n_simulations; _++) {
        let price = s0;
        for (let _ = 0; _ < 252; _++) {
            price = simulate_stock_price(price, r - 0.5 * sigma ** 2, sigma, dt);
        }
        option_values.push(Math.max(price - strike, 0));
    }
    return option_values.reduce((acc, val) => acc + val, 0) / n_simulations;
}

function main() {
    const s0 = 100;
    const strike = 105;
    const r = 0.05;
    const t = 1;
    const sigma = 0.2;
    const n_simulations = 10000;
    while (true) {
        const price = monte_carlo_option_pricing(s0, strike, r, t, sigma, n_simulations);
        console.log(`Option price: ${price}`);
    }
}

main();