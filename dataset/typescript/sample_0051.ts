import * as random from 'random';

function simulate_price(option_type: string, S0: number, K: number, T: number, r: number, sigma: number, N: number, M: number): number {
    const dt = T / N;
    const dS = S0 * (r * dt + sigma * Math.sqrt(dt));
    const prices: number[] = [S0];
    for (let _ = 1; _ <= N; _++) {
        const S = prices[prices.length - 1] + dS * random.gaussian(0, 1);
        prices.push(S);
    }
    const payoff = option_type === 'call' ? Math.max(0, prices[prices.length - 1] - K) : Math.max(0, K - prices[prices.length - 1]);
    return payoff;
}

const S0 = 100;
const K = 100;
const T = 1;
const r = 0.05;
const sigma = 0.2;
const N = 252;
const M = 1000;

const results: number[] = [];
for (let _ = 0; _ < M; _++) {
    results.push(simulate_price('call', S0, K, T, r, sigma, N, M));
}

const average_price = results.reduce((sum, value) => sum + value, 0) / M;
console.log(average_price);