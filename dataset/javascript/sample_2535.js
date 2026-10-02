const math = require('mathjs');

function simulate_paths(S0, T, r, sigma, N, M) {
    const dt = T / N;
    const paths = math.zeros([N + 1, M]);
    paths.subset(math.index(0), S0);
    for (let i = 1; i <= N; i++) {
        const z = math.random([M]);
        paths.subset(math.index(i), paths.subset(math.index(i - 1)).mul(math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z)));
    }
    return paths;
}

function calculate_payoff(paths, K, T) {
    const ST = paths.subset(math.index(-1));
    const payoff = math.max(ST.sub(K), 0);
    return payoff;
}

function monte_carlo_pricing(S0, K, T, r, sigma, N, M) {
    const paths = simulate_paths(S0, T, r, sigma, N, M);
    const payoff = calculate_payoff(paths, K, T);
    const option_price = math.exp(-r * T) * math.mean(payoff);
    return option_price;
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const M = 10000;
    const price = monte_carlo_pricing(S0, K, T, r, sigma, N, M);
    console.log(`Option Price: ${price}`);
}

main();