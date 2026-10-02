import * as math from 'mathjs';
import * as random from 'random';

function financial_model(S: number, K: number, T: number, r: number, sigma: number, N: number, M: number): number {
    const dt = T / N;
    let S_t = S;
    for (let _ = 0; _ < N; _++) {
        const z = random.normal(0, 1, M);
        S_t = S_t * math.exp((r - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * z);
    }
    const payoff = S_t.map(x => math.max(x - K, 0));
    const option_price = math.exp(-r * T) * math.mean(payoff);
    return option_price;
}

const result = financial_model(100, 100, 1, 0.05, 0.2, 100, 10000);
console.log(result);