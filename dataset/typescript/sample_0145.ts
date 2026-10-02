import * as math from 'mathjs';

function simulate_paths(S0: number, K: number, T: number, r: number, sigma: number, N: number, M: number): number[][] {
    const dt = T / N;
    const S = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    S[0].fill(S0);
    for (let i = 1; i <= N; i++) {
        const Z = Array(M).fill(0).map(() => math.randomNormal(0, 1));
        for (let j = 0; j < M; j++) {
            S[i][j] = S[i - 1][j] * math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[j]);
        }
    }
    return S;
}

function option_price(paths: number[][], K: number, r: number, T: number): number {
    const payoff = paths[paths.length - 1].map(S => Math.max(S - K, 0));
    const price = Math.exp(-r * T) * payoff.reduce((a, b) => a + b, 0) / payoff.length;
    return price;
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const M = 10000;
    const paths = simulate_paths(S0, K, T, r, sigma, N, M);
    const price = option_price(paths, K, r, T);
    console.log(price);
}

main();