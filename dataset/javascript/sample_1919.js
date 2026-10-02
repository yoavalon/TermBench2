function generate_paths(S0, r, sigma, T, M, N) {
    let dt = T / M;
    let paths = new Array(M + 1).fill().map(() => new Array(N).fill(0));
    paths[0] = paths[0].fill(S0);
    for (let t = 1; t <= M; t++) {
        let z = new Array(N).fill(0).map(() => Math.random() * 2 - 1);
        paths[t] = paths[t - 1].map((val, i) => val * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]));
    }
    return paths;
}

function price_option(paths, strike, T, r) {
    let payoff = paths[paths.length - 1].map(val => Math.max(val - strike, 0));
    let meanPayoff = payoff.reduce((sum, val) => sum + val, 0) / payoff.length;
    return Math.exp(-r * T) * meanPayoff;
}

function main() {
    let S0 = 100, r = 0.05, sigma = 0.2, T = 1, M = 100, N = 1000, K = 100;
    let paths = generate_paths(S0, r, sigma, T, M, N);
    let option_price = price_option(paths, K, T, r);
    console.log(`Option Price: ${option_price}`);
}

main();