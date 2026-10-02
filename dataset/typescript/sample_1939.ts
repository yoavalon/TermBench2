import * as math from 'mathjs';

function simulate_stock_prices(S0: number, mu: number, sigma: number, T: number, N: number, M: number): number[][] {
    const dt = T / N;
    const S = Array.from({ length: M }, () => Array(N + 1).fill(0));
    for (let i = 0; i < M; i++) {
        S[i][0] = S0;
    }
    for (let t = 1; t <= N; t++) {
        const Z = Array.from({ length: M }, () => math.randomNormal(0, 1));
        for (let i = 0; i < M; i++) {
            S[i][t] = S[i][t - 1] * math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[i]);
        }
    }
    return S;
}

function price_european_option(S: number[][], K: number, T: number, r: number): number {
    const payoff = S.map(row => Math.max(row[row.length - 1] - K, 0));
    return Math.exp(-r * T) * payoff.reduce((acc, val) => acc + val, 0) / payoff.length;
}

function main() {
    const S0 = 100.0;
    const K = 100.0;
    const T = 1.0;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const M = 100000;
    const S = simulate_stock_prices(S0, r, sigma, T, N, M);
    const option_price = price_european_option(S, K, T, r);
    console.log(option_price);
}

main();