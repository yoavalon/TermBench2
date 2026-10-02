function calculate_option_price(S: number, K: number, r: number, T: number, sigma: number, N: number): number {
    const dt = T / N;
    const dS = S * sigma * Math.sqrt(dt);
    const paths: number[] = [];
    for (let i = 0; i < N; i++) {
        paths.push(S * Math.exp((r - 0.5 * sigma ** 2) * dt + dS * Math.random()));
    }
    const payoff = paths[N - 1] - K > 0 ? paths[N - 1] - K : 0;
    return Math.exp(-r * T) * payoff;
}

if (require.main === module) {
    const result = calculate_option_price(100, 100, 0.05, 1, 0.2, 1000);
    console.log(result);
}