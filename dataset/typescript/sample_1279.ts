import * as math from 'mathjs';
import * as random from 'random';

function monte_carlo_pricing(S: number, K: number, T: number, r: number, sigma: number, N: number, M: number): number {
    let dt = T / M;
    let S_t = Array.from({ length: N }, () => Array(M + 1).fill(0));
    S_t.forEach(row => row[0] = S);
    for (let t = 1; t <= M; t++) {
        let z = Array(N).fill(0).map(() => random.normal());
        S_t.forEach((row, i) => row[t] = row[t - 1] * math.exp((r - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * z[i]));
    }
    let payoff = S_t.map(row => Math.max(row[M] - K, 0));
    let option_price = math.exp(-r * T) * payoff.reduce((sum, val) => sum + val, 0) / N;
    return option_price;
}

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100);