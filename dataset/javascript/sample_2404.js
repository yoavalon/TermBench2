function financial_model(S, K, T, r, sigma, N) {
    const dt = T / N;
    const dS = S * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Math.random());
    const payoff = Math.max(dS - K, 0);
    const option_price = Math.exp(-r * T) * payoff;
    return option_price;
}

financial_model(100, 100, 1, 0.05, 0.2, 1000);