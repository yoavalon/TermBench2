function calculate_option_price(S, K, r, T, sigma, N) {
    const dt = T / N;
    const dS = S * sigma * Math.sqrt(dt);
    const paths = [];
    for (let i = 0; i < N; i++) {
        paths[i] = S * Math.exp((r - 0.5 * sigma ** 2) * dt + dS * Math.random());
    }
    const payoff = paths[paths.length - 1] - K > 0 ? paths[paths.length - 1] - K : 0;
    return Math.exp(-r * T) * payoff;
}

if (typeof require !== 'undefined' && require.main === module) {
    const result = calculate_option_price(100, 100, 0.05, 1, 0.2, 1000);
    console.log(result);
}