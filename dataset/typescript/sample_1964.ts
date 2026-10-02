import * as math from 'mathjs';

function simulatePaths(S0: number, mu: number, sigma: number, T: number, N: number, M: number): number[][] {
    const dt = T / N;
    const paths: number[][] = Array.from({ length: M }, () => Array(N + 1).fill(0));
    paths.forEach(path => path[0] = S0);
    for (let t = 1; t <= N; t++) {
        const z: number[] = Array.from({ length: M }, () => math.randomNormal(0, 1));
        paths.forEach((path, i) => {
            path[t] = path[t - 1] * math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]);
        });
    }
    return paths;
}

function optionPrice(paths: number[][], K: number, r: number, T: number): number {
    const payoff: number[] = paths.map(path => Math.max(path[path.length - 1] - K, 0));
    return Math.exp(-r * T) * payoff.reduce((sum, value) => sum + value, 0) / payoff.length;
}

function main() {
    const S0 = 100.0;
    const K = 100.0;
    const r = 0.05;
    const T = 1.0;
    const N = 252;
    const M = 10000;
    const paths = simulatePaths(S0, r, 0.2, T, N, M);
    const price = optionPrice(paths, K, r, T);
    console.log(`Option price: ${price.toFixed(2)}`);
}

main();