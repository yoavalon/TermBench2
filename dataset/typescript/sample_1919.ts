const { random } = Math;
const { exp, sqrt, max } = Math;

function generate_paths(S0: number, r: number, sigma: number, T: number, M: number, N: number): number[][] {
    const dt = T / M;
    const paths: number[][] = Array.from({ length: M + 1 }, () => Array(N).fill(0));
    paths[0] = Array(N).fill(S0);
    for (let t = 1; t <= M; t++) {
        const z = Array(N).fill(0).map(() => random() * 2 - 1);
        paths[t] = paths[t - 1].map((S, i) => S * exp((r - 0.5 * sigma ** 2) * dt + sigma * sqrt(dt) * z[i]));
    }
    return paths;
}

function price_option(paths: number[][], strike: number, T: number, r: number): number {
    const payoff = paths[paths.length - 1].map(S => max(S - strike, 0));
    return exp(-r * T) * payoff.reduce((a, b) => a + b, 0) / payoff.length;
}

function main() {
    const S0 = 100, r = 0.05, sigma = 0.2, T = 1, M = 100, N = 1000, K = 100;
    const paths = generate_paths(S0, r, sigma, T, M, N);
    const option_price = price_option(paths, K, T, r);
    console.log(`Option Price: ${option_price}`);
}

main();