function monte_carlo_pricing(S, K, T, r, sigma, N) {
    let dt = T / N;
    let S_t = new Array(N + 1).fill(0);
    S_t[0] = S;
    let z = new Array(N);
    for (let i = 0; i < N; i++) {
        z[i] = Math.random() * 2 - 1;
    }
    for (let i = 1; i <= N; i++) {
        S_t[i] = S_t[i - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i - 1]);
    }
    let payoff = Math.max(S_t[N] - K, 0);
    let option_price = Math.exp(-r * T) * payoff;
    return option_price;
}

if (typeof require !== 'undefined' && require.main === module) {
    let result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000);
    console.log(result);
}