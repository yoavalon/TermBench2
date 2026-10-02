const random = require('mathjs').random;

function simulate_stock_price(S0, mu, sigma, T, dt) {
    let S = S0;
    for (let _ = 0; _ < Math.floor(T / dt); _++) {
        let dS = mu * S * dt + sigma * S * random() * Math.sqrt(dt);
        S += dS;
    }
    return S;
}

function monte_carlo_option_price(S0, K, T, r, sigma, N, dt) {
    let option_price = 0;
    for (let _ = 0; _ < N; _++) {
        let S_T = simulate_stock_price(S0, r, sigma, T, dt);
        option_price += Math.max(S_T - K, 0);
    }
    return option_price * (1 / N) * Math.exp(-r * T);
}

function main() {
    let S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2, N = 100000, dt = 0.01;
    let price = monte_carlo_option_price(S0, K, T, r, sigma, N, dt);
    console.log(`Option Price: ${price}`);
}

main();