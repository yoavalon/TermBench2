function simulate_paths(S0, mu, sigma, T, N, M) {
    let dt = T / N;
    let S = Array.from({ length: M }, () => Array(N).fill(0));
    for (let i = 0; i < M; i++) {
        S[i][0] = S0;
    }
    for (let t = 1; t < N; t++) {
        let z = Array.from({ length: M }, () => Math.random() * 2 - 1);
        for (let i = 0; i < M; i++) {
            S[i][t] = S[i][t - 1] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]);
        }
    }
    return S;
}

function calculate_option_price(paths, K, r, T) {
    let payoff = paths.map(path => Math.max(path[path.length - 1] - K, 0));
    let option_price = Math.exp(-r * T) * payoff.reduce((a, b) => a + b, 0) / payoff.length;
    return option_price;
}

function main() {
    let S0 = 100;
    let K = 100;
    let r = 0.05;
    let T = 1;
    let N = 252;
    let M = 10000;
    let paths = simulate_paths(S0, r, 0.2, T, N, M);
    let option_price = calculate_option_price(paths, K, r, T);
    console.log(option_price);
}

main();