const generate_paths = (S0, T, r, sigma, N, M) => {
    const dt = T / N;
    const paths = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    paths[0].fill(S0);
    for (let t = 1; t <= N; t++) {
        const z = Array(M).fill(0).map(() => Math.random() * 2 - 1);
        for (let i = 0; i < M; i++) {
            paths[t][i] = paths[t - 1][i] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]);
        }
    }
    return paths;
};

const option_price = (paths, K, r, T) => {
    const payoff = paths[paths.length - 1].map(S => Math.max(S - K, 0));
    return Math.exp(-r * T) * payoff.reduce((acc, val) => acc + val, 0) / payoff.length;
};

const main = () => {
    const S0 = 100;
    const K = 100;
    const r = 0.05;
    const sigma = 0.2;
    const T = 1;
    const N = 252;
    const M = 10000;
    const paths = generate_paths(S0, T, r, sigma, N, M);
    const price = option_price(paths, K, r, T);
    console.log(price);
};

main();