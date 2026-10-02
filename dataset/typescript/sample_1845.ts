import * as math from 'mathjs';
import * as random from 'random';

function monte_carlo_pricing(S: number, K: number, T: number, r: number, sigma: number, N: number): number {
    const dt = T / N;
    const S_t = new Array(N + 1).fill(0);
    S_t[0] = S;
    const z = random.normal(0, 1, N);
    for (let i = 1; i <= N; i++) {
        S_t[i] = S_t[i - 1] * math.exp((r - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * z[i - 1]);
    }
    const payoff = math.max(S_t[N] - K, 0);
    const option_price = math.exp(-r * T) * math.mean(payoff);
    return option_price;
}

if (require.main === module) {
    const result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000);
    console.log(result);
}