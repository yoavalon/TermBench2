import * as math from 'mathjs';

function monte_carlo_option_pricing(S: number, K: number, T: number, r: number, sigma: number, N: number): number {
    let dt = T / N;
    let St = S;
    let option_price = 0;
    for (let i = 0; i < N; i++) {
        St *= 1 + r * dt + sigma * math.randomNormal(0, 1) * Math.sqrt(dt);
    }
    option_price = Math.max(0, St - K);
    return option_price;
}

let S = 100, K = 100, T = 1, r = 0.05, sigma = 0.2, N = 252;
console.log(monte_carlo_option_pricing(S, K, T, r, sigma, N));