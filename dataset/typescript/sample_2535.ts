import * as math from 'mathjs';

function simulate_paths(S0: number, T: number, r: number, sigma: number, N: number, M: number): number[][] {
    let dt = T / N;
    let paths: number[][] = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    paths[0].fill(S0);
    for (let i = 1; i <= N; i++) {
        let z = Array(M).fill(0).map(() => math.randomNormal());
        paths[i] = paths[i - 1].map((val, j) => val * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[j]));
    }
    return paths;
}

function calculate_payoff(paths: number[][], K: number, T: number): number[] {
    let ST = paths[paths.length - 1];
    let payoff = ST.map(val => Math.max(val - K, 0));
    return payoff;
}

function monte_carlo_pricing(S0: number, K: number, T: number, r: number, sigma: number, N: number, M: number): number {
    let paths = simulate_paths(S0, T, r, sigma, N, M);
    let payoff = calculate_payoff(paths, K, T);
    let option_price = Math.exp(-r * T) * payoff.reduce((acc, val) => acc + val, 0) / M;
    return option_price;
}

function main() {
    let S0 = 100;
    let K = 100;
    let T = 1;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 10000;
    let price = monte_carlo_pricing(S0, K, T, r, sigma, N, M);
    console.log(`Option Price: ${price}`);
}

main();