import * as math from 'mathjs';

function generate_paths(S0: number, T: number, r: number, sigma: number, N: number, M: number): number[][] {
    const dt = T / N;
    const paths: number[][] = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    paths[0] = Array(M).fill(S0);
    for (let t = 1; t <= N; t++) {
        const z = Array(M).fill(0).map(() => math.randomNormal(0, 1));
        for (let m = 0; m < M; m++) {
            paths[t][m] = paths[t - 1][m] * math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[m]);
        }
    }
    return paths;
}

function calculate_payoffs(paths: number[][], K: number, option_type: string): number[] | null {
    if (option_type === 'call') {
        return paths[paths.length - 1].map(price => Math.max(price - K, 0));
    } else if (option_type === 'put') {
        return paths[paths.length - 1].map(price => Math.max(K - price, 0));
    }
    return null;
}

function price_option(S0: number, K: number, T: number, r: number, sigma: number, N: number, M: number, option_type: string): number {
    const paths = generate_paths(S0, T, r, sigma, N, M);
    const payoffs = calculate_payoffs(paths, K, option_type);
    if (payoffs) {
        return Math.exp(-r * T) * payoffs.reduce((sum, payoff) => sum + payoff, 0) / M;
    }
    return 0;
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const M = 10000;
    const option_type = 'call';
    const option_price = price_option(S0, K, T, r, sigma, N, M, option_type);
    console.log(`Option price: ${option_price.toFixed(2)}`);
}

main();