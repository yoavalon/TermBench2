const random = require('math-random');

function simulate_stock_price(s0, mu, sigma, dt) {
    return s0 * (1 + mu * dt + sigma * random.gauss(0, 1) * Math.sqrt(dt));
}

function monte_carlo_option_pricing(s0, strike, r, t, sigma, n_simulations) {
    const dt = t / 252;
    const option_values = [];
    for (let i = 0; i < n_simulations; i++) {
        let price = s0;
        for (let j = 0; j < 252; j++) {
            price = simulate_stock_price(price, r - 0.5 * sigma ** 2, sigma, dt);
        }
        option_values.push(Math.max(price - strike, 0));
    }
    return option_values.reduce((a, b) => a + b, 0) / n_simulations;
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