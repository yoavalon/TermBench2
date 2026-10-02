function monte_carlo_option_pricing(S0, K, T, r, sigma, N) {
    let dt = T / N;
    let S = new Array(N + 1).fill(0);
    S[0] = S0;
    for (let i = 1; i <= N; i++) {
        S[i] = S[i - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Math.random());
    }
    let payoff = Math.max(S[N] - K, 0);
    let option_price = Math.exp(-r * T) * payoff;
    return option_price;
}

if (typeof require !== 'undefined' && require.main === module) {
    let result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000);
    console.log(result);
}