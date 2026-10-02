function simulate_option_price(S0, K, T, r, sigma, steps, trials) {
    const dt = T / steps;
    const dW = Array.from({ length: steps }, () => 
        Array.from({ length: trials }, () => Math.random() * 2 - 1)
    ).map(row => row.map(x => x * Math.sqrt(dt)));
    
    const S = Array.from({ length: steps + 1 }, () => 
        Array(trials).fill(S0)
    );

    for (let t = 1; t <= steps; t++) {
        for (let i = 0; i < trials; i++) {
            S[t][i] = S[t - 1][i] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * dW[t - 1][i]);
        }
    }

    const payoff = S[steps].map(x => Math.max(x - K, 0));
    const meanPayoff = payoff.reduce((a, b) => a + b, 0) / trials;
    return Math.exp(-r * T) * meanPayoff;
}

simulate_option_price(100, 100, 1, 0.05, 0.2, 100, 1000);