const { randomNormal } = require('mathjs');

function simulatePaths(S0, K, T, r, sigma, N, M) {
    const dt = T / N;
    const paths = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    paths[0] = Array(M).fill(S0);
    for (let i = 1; i <= N; i++) {
        const Z = Array(M).fill(0).map(() => randomNormal());
        paths[i] = paths[i - 1].map((value, j) => value * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[j]));
    }
    return paths;
}

function calculatePayoffs(paths, K, T, r, M) {
    const S_T = paths[paths.length - 1];
    const payoff = S_T.map(value => Math.max(value - K, 0));
    const optionValue = Math.exp(-r * T) * payoff.reduce((acc, val) => acc + val, 0) / M;
    return optionValue;
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 252;
    const M = 100000;
    while (true) {
        const paths = simulatePaths(S0, K, T, r, sigma, N, M);
        const optionValue = calculatePayoffs(paths, K, T, r, M);
        console.log(optionValue);
    }
}

main();