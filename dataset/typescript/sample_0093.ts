function monte_carlo_pricing(S0: number, K: number, T: number, r: number, sigma: number, N: number, M: number): number {
    const dt = T / M;
    const S: number[][] = Array.from({ length: M + 1 }, () => Array(N).fill(0));
    S[0] = Array(N).fill(S0);
    for (let t = 1; t <= M; t++) {
        const Z = Array(N).fill(0).map(() => Math.random() * 2 - 1);
        for (let i = 0; i < N; i++) {
            S[t][i] = S[t - 1][i] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[i]);
        }
    }
    const payoff = S[M].map(price => Math.max(price - K, 0));
    return Math.exp(-r * T) * payoff.reduce((sum, value) => sum + value, 0) / N;
}

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100);