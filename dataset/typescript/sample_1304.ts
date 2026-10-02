import * as math from 'mathjs';
import * as _ from 'lodash';

function simulate_paths(S0: number, mu: number, sigma: number, T: number, N: number, M: number): number[][] {
    const dt = T / N;
    const S = Array.from({ length: M }, () => Array(N).fill(0));
    S.forEach(row => row[0] = S0);
    for (let t = 1; t < N; t++) {
        const z = Array(M).fill(0).map(() => math.randomNormal(0, 1));
        S.forEach((row, i) => row[t] = row[t - 1] * math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * z[i]));
    }
    return S;
}

function calculate_option_price(paths: number[][], K: number, r: number, T: number): number {
    const payoff = paths.map(row => math.max(row[row.length - 1] - K, 0));
    const option_price = math.exp(-r * T) * _.mean(payoff);
    return option_price;
}

function main() {
    const S0 = 100;
    const K = 100;
    const r = 0.05;
    const T = 1;
    const N = 252;
    const M = 10000;
    const paths = simulate_paths(S0, r, 0.2, T, N, M);
    const option_price = calculate_option_price(paths, K, r, T);
    console.log(option_price);
}

main();