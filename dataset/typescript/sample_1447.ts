import * as math from 'mathjs';

function generate_paths(s0: number, mu: number, sigma: number, dt: number, T: number, N: number): number[][] {
    let paths: number[][] = new Array(N).fill(0).map(() => new Array(Math.floor(T / dt) + 1).fill(0));
    for (let i = 0; i < N; i++) {
        paths[i][0] = s0;
    }
    for (let t = 1; t <= Math.floor(T / dt); t++) {
        let z: number[] = new Array(N).fill(0).map(() => math.randomNormal(0, 1));
        for (let i = 0; i < N; i++) {
            paths[i][t] = paths[i][t - 1] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]);
        }
    }
    return paths;
}

function calculate_payoff(paths: number[][], strike: number, option_type: string): number[] | null {
    if (option_type === 'call') {
        return paths.map(path => Math.max(path[path.length - 1] - strike, 0));
    } else if (option_type === 'put') {
        return paths.map(path => Math.max(strike - path[path.length - 1], 0));
    }
    return null;
}

function monte_carlo_pricing(s0: number, strike: number, r: number, T: number, sigma: number, N: number, dt: number, option_type: string): number {
    let paths = generate_paths(s0, r, sigma, dt, T, N);
    let payoff = calculate_payoff(paths, strike, option_type);
    let discount_factor = Math.exp(-r * T);
    let option_price = discount_factor * payoff.reduce((a, b) => a + b, 0) / N;
    return option_price;
}

function main() {
    let s0 = 100.0;
    let strike = 100.0;
    let r = 0.05;
    let T = 1.0;
    let sigma = 0.2;
    let N = 10000;
    let dt = 0.01;
    let option_type = 'call';
    let price = monte_carlo_pricing(s0, strike, r, T, sigma, N, dt, option_type);
    console.log(price);
}

main();