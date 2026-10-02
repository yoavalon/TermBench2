import * as math from 'mathjs';

function simulate_monte_carlo(S0: number, K: number, T: number, r: number, sigma: number, N: number): number {
    let dt = T / N;
    let S = new Array(N + 1).fill(0);
    S[0] = S0;
    for (let i = 1; i <= N; i++) {
        let z = math.randomNormal(0, 1);
        S[i] = S[i - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z);
    }
    return Math.exp(-r * T) * Math.max(S[N] - K, 0);
}

function main() {
    let S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2, N = 1000;
    let option_price = simulate_monte_carlo(S0, K, T, r, sigma, N);
    console.log(option_price);
}

main();