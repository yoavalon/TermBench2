function simulatePaths(S0, mu, sigma, T, N, M) {
    const dt = T / N;
    const paths = new Array(N + 1).fill().map(() => new Array(M).fill(0));
    paths[0] = paths[0].fill(S0);
    for (let t = 1; t <= N; t++) {
        const rand = new Array(M).fill().map(() => Math.random() * 2 - 1);
        for (let i = 0; i < M; i++) {
            paths[t][i] = paths[t - 1][i] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * rand[i]);
        }
    }
    return paths;
}

function optionPrice(paths, K, r, T) {
    const payoff = paths[paths.length - 1].map(S => Math.max(S - K, 0));
    const meanPayoff = payoff.reduce((acc, val) => acc + val, 0) / payoff.length;
    return Math.exp(-r * T) * meanPayoff;
}

function main() {
    const S0 = 100;
    const K = 100;
    const r = 0.05;
    const T = 1;
    const N = 252;
    const M = 10000;
    const paths = simulatePaths(S0, r, 0.2, T, N, M);
    const price = optionPrice(paths, K, r, T);
    console.log(`Option Price: ${price.toFixed(4)}`);
}

main();