function monte_carlo_pricing(S, K, T, r, sigma, N, M) {
    const dt = T / M;
    const S_t = Array.from({ length: N }, () => Array(M + 1).fill(0));
    for (let i = 0; i < N; i++) {
        S_t[i][0] = S;
    }
    for (let t = 1; t <= M; t++) {
        const z = Array.from({ length: N }, () => Math.random() * 2 - 1);
        for (let i = 0; i < N; i++) {
            S_t[i][t] = S_t[i][t - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]);
        }
    }
    const payoff = S_t.map(row => Math.max(row[row.length - 1] - K, 0));
    const option_price = Math.exp(-r * T) * payoff.reduce((acc, val) => acc + val, 0) / N;
    return option_price;
}

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100);