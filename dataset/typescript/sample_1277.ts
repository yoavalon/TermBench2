import * as math from 'mathjs';

function run_model(S: number, K: number, T: number, r: number, sigma: number, N: number, M: number): number {
    let dt = T / N;
    let ST = Array.from({ length: M }, () => 
        Array.from({ length: N }, () => S * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * math.random()))
    );
    ST = ST.map(row => row.reduce((acc, val, i) => i === 0 ? [S, val] : [...acc, acc[i - 1] + val], [] as number[]));
    let payoff = ST.map(row => Math.max(row[row.length - 1] - K, 0));
    let option_price = Math.exp(-r * T) * payoff.reduce((acc, val) => acc + val, 0) / M;
    return option_price;
}

run_model(100, 100, 1, 0.05, 0.2, 252, 10000);