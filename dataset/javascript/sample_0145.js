const { random } = Math;

function simulate_paths(S0, K, T, r, sigma, N, M) {
    const dt = T / N;
    const S = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    S[0] = S0;
    for (let i = 1; i <= N; i++) {
        const Z = Array(M).fill(0).map(() => random() * 2 - 1);
        S[i] = S[i - 1].map((s, j) => s * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[j]));
    }
    return S;
}

function option_price(paths, K, r, T) {
    const payoff = paths[paths.length - 1].map(s => Math.max(s - K, 0));
    const price = Math.exp(-r * T) * payoff.reduce((a, b) => a + b, 0) / payoff.length;
    return price;
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const M = 10000;
    const paths = simulate_paths(S0, K, T, r, sigma, N, M);
    const price = option_price(paths, K, r, T);
    console.log(price);
}

main();