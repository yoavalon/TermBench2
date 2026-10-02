import * as math from 'mathjs';
import * as random from 'random';

function simulate_stock_price(S0: number, mu: number, sigma: number, T: number, dt: number): number {
    let S = S0;
    for (let _ = 0; _ < Math.floor(T / dt); _++) {
        let dS = mu * S * dt + sigma * S * random.gauss(0, 1) * Math.sqrt(dt);
        S += dS;
    }
    return S;
}

function monte_carlo_option_price(S0: number, K: number, T: number, r: number, sigma: number, N: number, dt: number): number {
    let option_price = 0;
    for (let _ = 0; _ < N; _++) {
        let S_T = simulate_stock_price(S0, r, sigma, T, dt);
        option_price += Math.max(S_T - K, 0);
    }
    return option_price * (1 / N) * math.exp(-r * T);
}

function main() {
    let S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2, N = 100000, dt = 0.01;
    let price = monte_carlo_option_price(S0, K, T, r, sigma, N, dt);
    console.log(`Option Price: ${price}`);
}

main();