function generate_paths(S0, mu, sigma, T, N, M) {
    let paths = Array.from({ length: M }, () => [S0]);
    let dt = T / N;
    for (let i = 1; i <= N; i++) {
        for (let j = 0; j < M; j++) {
            let Z = Math.random() * 2 - 1;
            let S = paths[j][paths[j].length - 1] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z);
            paths[j].push(S);
        }
    }
    return paths;
}

function payoff_function(S, K, option_type) {
    if (option_type === 'call') {
        return Math.max(S - K, 0);
    } else if (option_type === 'put') {
        return Math.max(K - S, 0);
    }
    return 0;
}

function monte_carlo_pricing(paths, K, r, T, option_type) {
    let payoffs = paths.map(path => payoff_function(path[path.length - 1], K, option_type));
    let present_value = Math.exp(-r * T) * payoffs.reduce((acc, val) => acc + val, 0) / payoffs.length;
    return present_value;
}

function main() {
    let S0 = 100;
    let K = 100;
    let r = 0.05;
    let T = 1;
    let N = 100;
    let M = 10000;
    let option_type = 'call';
    let paths = generate_paths(S0, r, 0.2, T, N, M);
    let price = monte_carlo_pricing(paths, K, r, T, option_type);
    console.log(`Option price: ${price}`);
}

main();