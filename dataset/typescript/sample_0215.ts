import * as math from 'mathjs';
import * as random from 'random';

function simulate_paths(S0: number, T: number, r: number, sigma: number, N: number, M: number): number[][] {
    const dt = T / N;
    const paths: number[][] = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    paths[0].fill(S0);
    for (let t = 1; t <= N; t++) {
        const z = Array(M).fill(0).map(() => random.normal(0, 1));
        for (let i = 0; i < M; i++) {
            paths[t][i] = paths[t - 1][i] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]);
        }
    }
    return paths;
}

function payoff_function(paths: number[][], K: number, option_type: string): number[] {
    if (option_type === 'call') {
        return paths[paths.length - 1].map(S => Math.max(S - K, 0));
    } else if (option_type === 'put') {
        return paths[paths.length - 1].map(S => Math.max(K - S, 0));
    }
    return [];
}

function price_option(S0: number, K: number, T: number, r: number, sigma: number, N: number, M: number, option_type: string): number {
    const paths = simulate_paths(S0, T, r, sigma, N, M);
    const payoff = payoff_function(paths, K, option_type);
    return Math.exp(-r * T) * payoff.reduce((acc, val) => acc + val, 0) / M;
}

function main() {
    const S0 = 100.0;
    const K = 100.0;
    const T = 1.0;
    const r = 0.05;
    const sigma = 0.2;
    const N = 252;
    const M = 10000;
    const option_type = 'call';
    const option_price = price_option(S0, K, T, r, sigma, N, M, option_type);
    console.log(`Option Price: ${option_price}`);
}

main();