import * as math from 'mathjs';

function simulate_paths(S0: number, T: number, r: number, sigma: number, N: number, M: number): number[][] {
    const dt = T / N;
    const paths: number[][] = Array.from({ length: M }, () => Array(N + 1).fill(0));
    paths.forEach(path => path[0] = S0);
    for (let t = 1; t <= N; t++) {
        const z = Array(M).fill(0).map(() => math.randomNormal(0, 1));
        paths.forEach((path, i) => path[t] = path[t - 1] * math.exp((r - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * z[i]));
    }
    return paths;
}

function price_option(paths: number[][], strike: number, option_type: string): number {
    let payoff: number[] = [];
    if (option_type === 'call') {
        payoff = paths.map(path => Math.max(path[path.length - 1] - strike, 0));
    } else if (option_type === 'put') {
        payoff = paths.map(path => Math.max(strike - path[path.length - 1], 0));
    }
    return Math.exp(-r * T) * payoff.reduce((a, b) => a + b, 0) / payoff.length;
}

const S0 = 100;
const T = 1;
const r = 0.05;
const sigma = 0.2;
const N = 252;
const M = 10000;
const strike = 100;
const option_type = 'call';

function main() {
    while (true) {
        const paths = simulate_paths(S0, T, r, sigma, N, M);
        const price = price_option(paths, strike, option_type);
        console.log(price);
    }
}

main();