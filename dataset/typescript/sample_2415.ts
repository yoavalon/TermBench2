function simulateOptionPrice(S0: number, K: number, T: number, r: number, sigma: number, steps: number, trials: number): number {
    const dt = T / steps;
    const dW: number[][] = Array.from({ length: steps }, () => Array.from({ length: trials }, () => Math.random() * Math.sqrt(dt) * 2 - Math.sqrt(dt)));
    const S: number[][] = Array.from({ length: steps }, () => Array(trials));
    S[0] = Array(trials).fill(S0);

    for (let i = 1; i < steps; i++) {
        for (let j = 0; j < trials; j++) {
            S[i][j] = S[i - 1][j] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * dW[i][j]);
        }
    }

    const payoff = S[steps - 1].map(price => Math.max(price - K, 0));
    const meanPayoff = payoff.reduce((sum, value) => sum + value, 0) / trials;
    return Math.exp(-r * T) * meanPayoff;
}

simulateOptionPrice(100, 100, 1, 0.05, 0.2, 100, 1000);