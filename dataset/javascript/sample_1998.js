const { random } = require('mathjs');

function simulate_paths(S0, T, r, sigma, N, M) {
    const dt = T / M;
    const paths = Array.from({ length: N }, () => Array(M).fill(0));
    paths.forEach(path => path[0] = S0);
    for (let t = 1; t < M; t++) {
        const z = random(N).map(Math.random);
        paths.forEach((path, i) => path[t] = path[t - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]));
    }
    return paths;
}

function option_pricing(paths, K, T, r, M) {
    const payoff = paths.map(path => Math.max(path[M - 1] - K, 0));
    const price = Math.exp(-r * T) * payoff.reduce((acc, val) => acc + val, 0) / payoff.length;
    return price;
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 10000;
    const M = 100;
    const paths = simulate_paths(S0, T, r, sigma, N, M);
    const option_price = option_pricing(paths, K, T, r, M);
    console.log(option_price);
}

main();