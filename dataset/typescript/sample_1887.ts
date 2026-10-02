import * as math from 'mathjs';

function monte_carlo_option_pricing(S: number, K: number, T: number, r: number, sigma: number, N: number): number {
    const dt = T / N;
    const S_T = Array.from({ length: N }, () => 
        S * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * math.randomNormal(0, 1))
    );
    return Math.exp(-r * T) * S_T.reduce((acc, val) => acc + Math.max(val - K, 0), 0) / N;
}

if (require.main === module) {
    const result = monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 10000);
    console.log(result);
}