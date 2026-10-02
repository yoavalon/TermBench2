function financial_model(S, K, T, r, sigma, N, M) {
    let dt = T / N;
    let S_t = S;
    for (let i = 0; i < N; i++) {
        let z = new Array(M).fill(0).map(() => Math.random() * 2 - 1);
        S_t = S_t * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z);
    }
    let payoff = S_t.map(x => Math.max(x - K, 0));
    let option_price = Math.exp(-r * T) * payoff.reduce((a, b) => a + b, 0) / M;
    return option_price;
}
let result = financial_model(100, 100, 1, 0.05, 0.2, 100, 10000);
console.log(result);