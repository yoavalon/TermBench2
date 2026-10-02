import * as math from 'mathjs';

function simulate_paths(S0: number, K: number, T: number, r: number, sigma: number, N: number, M: number): number[][] {
    const dt = T / N;
    const paths: number[][] = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    paths[0].fill(S0);
    for (let i = 1; i <= N; i++) {
        const Z = Array(M).fill(0).map(() => math.randomNormal(0, 1));
        for (let j = 0; j < M; j++) {
            paths[i][j] = paths[i - 1][j] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[j]);
        }
    }
    return paths;
}

function calculate_payoffs(paths: number[][], K: number, T: number, r: number, M: number): number {
    const S_T = paths[paths.length - 1];
    const payoff = S_T.map(S => Math.max(S - K, 0));
    const option_value = Math.exp(-r * T) * payoff.reduce((a, b) => a + b, 0) / M;
    return option_value;
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 252;
    const M = 100000;
    while (true) {
        const paths = simulate_paths(S0, K, T, r, sigma, N, M);
        const option_value = calculate_payoffs(paths, K, T, r, M);
        console.log(option_value);
    }
}

main();