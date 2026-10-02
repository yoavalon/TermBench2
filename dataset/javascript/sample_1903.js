const random = require('math-random');
const math = require('mathjs');

function simulate_option_price(S0, K, T, r, sigma, N) {
    const dt = T / N;
    let S = S0;
    for (let i = 0; i < N; i++) {
        S *= math.exp((r - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * random.gauss(0, 1));
    }
    return math.max(S - K, 0);
}

function monte_carlo_pricing(S0, K, T, r, sigma, M, N) {
    let total = 0;
    for (let i = 0; i < M; i++) {
        total += simulate_option_price(S0, K, T, r, sigma, N);
    }
    return total / M * math.exp(-r * T);
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const M = 1000;
    const N = 100;
    console.log(monte_carlo_pricing(S0, K, T, r, sigma, M, N));
}

main();