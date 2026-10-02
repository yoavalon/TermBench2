function simulate_paths(S0, mu, sigma, T, N, M) {
    let dt = T / N;
    let paths = Array.from({ length: M }, () => [S0]);
    for (let i = 1; i <= N; i++) {
        for (let j = 0; j < M; j++) {
            let dW = Math.random() * Math.sqrt(dt);
            paths[j].push(paths[j][paths[j].length - 1] * (1 + mu * dt + sigma * dW));
        }
    }
    return paths;
}

function option_price(paths, K, r, T) {
    let payoff = paths.map(path => Math.max(path[path.length - 1] - K, 0));
    let discounted_payoff = payoff.map(p => p * (1 - r * T));
    return discounted_payoff.reduce((acc, val) => acc + val, 0) / discounted_payoff.length;
}

function main() {
    let S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2;
    let N = 100, M = 1000;
    let paths = simulate_paths(S0, mu = r, sigma = sigma, T = T, N = N, M = M);
    let price = option_price(paths, K, r, T);
    console.log(price);
}

main();