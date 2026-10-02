import * as math from 'mathjs';

function monte_carlo_option_pricing(S0: number, K: number, T: number, r: number, sigma: number, N: number): number {
    let dt = T / N;
    let S = new Array(N + 1).fill(0);
    S[0] = S0;
    for (let i = 1; i <= N; i++) {
        S[i] = S[i - 1] * math.exp((r - 0.5 * math.pow(sigma, 2)) * dt + sigma * math.sqrt(dt) * math.random());
    }
    let payoff = math.max(S[N] - K, 0);
    let option_price = math.exp(-r * T) * payoff;
    return option_price;
}

if (require.main === module) {
    let result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 1000);
    console.log(result);
}