function financial_model(S: number, K: number, T: number, r: number, sigma: number, N: number): number {
    const dt = T / N;
    const dS = S * Math.exp((r - 0.5 * Math.pow(sigma, 2)) * dt + sigma * Math.sqrt(dt) * Math.random());
    const payoff = Math.max(dS - K, 0);
    const option_price = Math.exp(-r * T) * payoff;
    return option_price;
}

if (require.main === module) {
    financial_model(100, 100, 1, 0.05, 0.2, 1000);
}