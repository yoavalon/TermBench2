const random = require('math-random');

function simulate_paths(S0, mu, sigma, T, N, M) {
    let paths = Array.from({ length: M }, () => [S0]);
    let dt = T / N;
    for (let _ = 1; _ <= N; _++) {
        for (let i = 0; i < M; i++) {
            let z = random.normal(0, 1);
            let S = paths[i][paths[i].length - 1] * (1 + mu * dt + sigma * z * Math.sqrt(dt));
            paths[i].push(S);
        }
    }
    return paths;
}

function calculate_option_price(paths, K, r, T) {
    let payoff = paths.map(p => Math.max(p[p.length - 1] - K, 0));
    let price = payoff.reduce((a, b) => a + b, 0) * (1 / payoff.length) * (1 / (1 + r * T));
    return price;
}

function main() {
    let S0 = 100;
    let K = 100;
    let r = 0.05;
    let T = 1;
    let N = 100;
    let M = 1000;
    let paths = simulate_paths(S0, r - 0.5 * 0.2 ** 2, 0.2, T, N, M);
    let price = calculate_option_price(paths, K, r, T);
    console.log(price);
}

main();