const { random, exp, max, mean } = Math;

function simulatePaths(S0, T, r, sigma, N, M) {
    const dt = T / N;
    const paths = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    paths[0].fill(S0);
    for (let t = 1; t <= N; t++) {
        const z = Array.from({ length: M }, () => random() * 2 - 1);
        for (let i = 0; i < M; i++) {
            paths[t][i] = paths[t - 1][i] * exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]);
        }
    }
    return paths;
}

function payoffFunction(paths, K, optionType) {
    if (optionType === 'call') {
        return paths[paths.length - 1].map(S => max(S - K, 0));
    } else if (optionType === 'put') {
        return paths[paths.length - 1].map(S => max(K - S, 0));
    }
}

function priceOption(S0, K, T, r, sigma, N, M, optionType) {
    const paths = simulatePaths(S0, T, r, sigma, N, M);
    const payoff = payoffFunction(paths, K, optionType);
    return exp(-r * T) * mean(payoff);
}

function main() {
    const S0 = 100.0;
    const K = 100.0;
    const T = 1.0;
    const r = 0.05;
    const sigma = 0.2;
    const N = 252;
    const M = 10000;
    const optionType = 'call';
    const optionPrice = priceOption(S0, K, T, r, sigma, N, M, optionType);
    console.log(`Option Price: ${optionPrice}`);
}

main();