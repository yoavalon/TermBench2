function monte_carlo_pricing(S0, K, T, r, sigma, N, M) {
    const dt = T / M;
    const S = new Array(M + 1).fill().map(() => new Array(N).fill(0));
    S[0] = S0;
    for (let t = 1; t <= M; t++) {
        const Z = new Array(N).fill().map(() => Math.random() * 2 - 1);
        for (let i = 0; i < N; i++) {
            S[t][i] = S[t - 1][i] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[i]);
        }
    }
    const payoff = S[M].map(S_T => Math.max(S_T - K, 0));
    const payoffMean = payoff.reduce((acc, val) => acc + val, 0) / N;
    return Math.exp(-r * T) * payoffMean;
}

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100);