import * as math from 'mathjs';

function simulate_paths(S0: number, T: number, r: number, sigma: number, N: number, M: number): number[][] {
    const dt = T / N;
    const paths: number[][] = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    paths[0].fill(S0);
    for (let t = 1; t <= N; t++) {
        const Z = Array(M).fill(0).map(() => math.randomNormal(0, 1));
        for (let i = 0; i < M; i++) {
            paths[t][i] = paths[t - 1][i] * math.exp((r - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * Z[i]);
        }
    }
    return paths;
}

function option_price(paths: number[][], K: number, r: number, T: number, N: number): number {
    const discounted_payoffs = paths[N].map(S => math.exp(-r * T) * Math.max(S - K, 0));
    return discounted_payoffs.reduce((sum, value) => sum + value, 0) / discounted_payoffs.length;
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const M = 10000;
    const paths = simulate_paths(S0, T, r, sigma, N, M);
    const price = option_price(paths, K, r, T, N);
    console.log(price);
}

main();