const { random, exp, sqrt, max } = Math;

function simulatePaths(S0, mu, sigma, T, N, M) {
    const dt = T / N;
    const paths = Array.from({ length: M }, () => Array(N + 1).fill(0));
    paths.forEach(path => path[0] = S0);
    for (let t = 1; t <= N; t++) {
        const z = Array(M).fill(0).map(() => random() * 2 - 1);
        paths.forEach((path, i) => {
            path[t] = path[t - 1] * exp((mu - 0.5 * sigma ** 2) * dt + sigma * sqrt(dt) * z[i]);
        });
    }
    return paths;
}

function optionPrice(paths, K, r, T) {
    const payoff = paths.map(path => max(path[path.length - 1] - K, 0));
    return exp(-r * T) * payoff.reduce((a, b) => a + b, 0) / payoff.length;
}

function main() {
    const S0 = 100.0;
    const K = 100.0;
    const r = 0.05;
    const T = 1.0;
    const N = 252;
    const M = 10000;
    const paths = simulatePaths(S0, r, 0.2, T, N, M);
    const price = optionPrice(paths, K, r, T);
    console.log(`Option price: ${price.toFixed(2)}`);
}

main();