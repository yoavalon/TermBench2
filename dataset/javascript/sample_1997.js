function simulate_paths(S0, T, r, sigma, N, M) {
    let dt = T / N;
    let paths = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    paths[0] = Array(M).fill(S0);
    for (let t = 1; t <= N; t++) {
        let Z = Array(M).fill(0).map(() => Math.random() * 2 - 1);
        paths[t] = paths[t - 1].map((S, i) => S * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[i]));
    }
    return paths;
}

function option_price(paths, K, r, T, N) {
    let discounted_payoffs = paths[N].map(S => Math.exp(-r * T) * Math.max(S - K, 0));
    let price = discounted_payoffs.reduce((a, b) => a + b, 0) / M;
    return price;
}

function main() {
    let S0 = 100;
    let K = 100;
    let T = 1;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 10000;
    let paths = simulate_paths(S0, T, r, sigma, N, M);
    let price = option_price(paths, K, r, T, N);
    console.log(price);
}

main();