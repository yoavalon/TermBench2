import * as math from 'mathjs';

function simulate_paths(S0: number, mu: number, sigma: number, T: number, N: number, M: number): number[][] {
    const dt = T / N;
    const paths: number[][] = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    paths[0].fill(S0);
    for (let t = 1; t <= N; t++) {
        const rand = Array(M).fill(0).map(() => math.randomNormal(0, 1));
        for (let m = 0; m < M; m++) {
            paths[t][m] = paths[t - 1][m] * math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * rand[m]);
        }
    }
    return paths;
}

function option_price(paths: number[][], K: number, r: number, T: number): number {
    const payoff = paths[paths.length - 1].map(S => Math.max(S - K, 0));
    return Math.exp(-r * T) * math.mean(payoff);
}

function main() {
    const S0 = 100;
    const K = 100;
    const r = 0.05;
    const T = 1;
    const N = 252;
    const M = 10000;
    const paths = simulate_paths(S0, r, 0.2, T, N, M);
    const price = option_price(paths, K, r, T);
    console.log(`Option Price: ${price.toFixed(4)}`);
}

main();