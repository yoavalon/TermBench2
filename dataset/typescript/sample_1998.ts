import * as math from 'mathjs';

function simulate_paths(S0: number, T: number, r: number, sigma: number, N: number, M: number): number[][] {
    const dt = T / M;
    const paths: number[][] = Array.from({ length: N }, () => Array(M).fill(0));
    for (let i = 0; i < N; i++) {
        paths[i][0] = S0;
    }
    for (let t = 1; t < M; t++) {
        const z = Array(N).fill(0).map(() => math.randomNormal(0, 1));
        for (let i = 0; i < N; i++) {
            paths[i][t] = paths[i][t - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]);
        }
    }
    return paths;
}

function option_pricing(paths: number[][], K: number, T: number, r: number, M: number): number {
    const payoff = paths.map(path => Math.max(path[path.length - 1] - K, 0));
    const price = Math.exp(-r * T) * payoff.reduce((a, b) => a + b, 0) / payoff.length;
    return price;
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 10000;
    const M = 100;
    const paths = simulate_paths(S0, T, r, sigma, N, M);
    const option_price = option_pricing(paths, K, T, r, M);
    console.log(option_price);
}

main();