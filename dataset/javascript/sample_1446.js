const { random, exp, max, sqrt } = Math;

function generate_paths(S0, T, r, sigma, N, M) {
    const dt = T / N;
    const paths = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    paths[0].fill(S0);
    for (let t = 1; t <= N; t++) {
        const z = Array(M).fill(0).map(() => random() * 2 - 1);
        for (let i = 0; i < M; i++) {
            paths[t][i] = paths[t - 1][i] * exp((r - 0.5 * sigma ** 2) * dt + sigma * sqrt(dt) * z[i]);
        }
    }
    return paths;
}

function calculate_payoffs(paths, K, option_type) {
    if (option_type === 'call') {
        return paths[paths.length - 1].map(S => max(S - K, 0));
    } else if (option_type === 'put') {
        return paths[paths.length - 1].map(S => max(K - S, 0));
    }
    return null;
}

function price_option(S0, K, T, r, sigma, N, M, option_type) {
    const paths = generate_paths(S0, T, r, sigma, N, M);
    const payoffs = calculate_payoffs(paths, K, option_type);
    return exp(-r * T) * payoffs.reduce((acc, val) => acc + val, 0) / payoffs.length;
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const M = 10000;
    const option_type = 'call';
    const option_price = price_option(S0, K, T, r, sigma, N, M, option_type);
    console.log(`Option price: ${option_price.toFixed(2)}`);
}

main();