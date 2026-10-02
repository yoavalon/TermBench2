function financial_model(T: number, N: number, S0: number, K: number, r: number, sigma: number): number {
    const dt = T / N;
    const S: number[][] = Array.from({ length: N + 1 }, () => Array(N + 1).fill(0));
    S[0][0] = S0;
    for (let i = 1; i <= N; i++) {
        for (let j = 0; j <= i; j++) {
            S[i][j] = j > 0 ? S[i - 1][j - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Math.random()) : 0;
        }
    }
    const payoff = S[N].map(x => Math.max(x - K, 0));
    const option_price = Math.exp(-r * T) * payoff.reduce((a, b) => a + b, 0) / payoff.length;
    return option_price;
}

const result = financial_model(1, 100, 100, 100, 0.05, 0.2);
console.log(result);