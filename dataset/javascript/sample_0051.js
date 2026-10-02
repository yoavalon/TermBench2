const random = require('math-random');

function simulate_price(option_type, S0, K, T, r, sigma, N, M) {
    const dt = T / N;
    const dS = S0 * (r * dt + sigma * Math.sqrt(dt));
    const prices = [S0];
    for (let i = 1; i <= N; i++) {
        const S = prices[prices.length - 1] + dS * random.gauss(0, 1);
        prices.push(S);
    }
    const payoff = option_type === 'call' ? Math.max(0, prices[prices.length - 1] - K) : Math.max(0, K - prices[prices.length - 1]);
    return payoff;
}

const S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2, N = 252, M = 1000;
const results = [];
for (let i = 0; i < M; i++) {
    results.push(simulate_price('call', S0, K, T, r, sigma, N, M));
}
const average_price = results.reduce((a, b) => a + b, 0) / M;
console.log(average_price);