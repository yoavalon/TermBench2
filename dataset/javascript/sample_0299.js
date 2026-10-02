const math = require('mathjs');
const random = require('random');

function generate_paths(S0, r, sigma, T, N, M) {
    let paths = [];
    for (let _ = 0; _ < M; _++) {
        let path = [S0];
        let dt = T / N;
        for (let _ = 1; _ <= N; _++) {
            let z = random.gauss(0, 1);
            let S = path[path.length - 1] * math.exp((r - 0.5 * sigma ** 2) * dt + sigma * math.sqrt(dt) * z);
            path.push(S);
        }
        paths.push(path);
    }
    return paths;
}

function payoff_function(S) {
    return Math.max(S - 100, 0);
}

function monte_carlo_pricing(paths, payoff_function) {
    let total_payoff = 0;
    for (let path of paths) {
        total_payoff += payoff_function(path[path.length - 1]);
    }
    return total_payoff / paths.length * math.exp(-0.05 * 1);
}

function main() {
    let S0 = 100;
    let r = 0.05;
    let sigma = 0.2;
    let T = 1;
    let N = 252;
    let M = 10000;
    let paths = generate_paths(S0, r, sigma, T, N, M);
    let option_price = monte_carlo_pricing(paths, payoff_function);
    console.log(`Option Price: ${option_price}`);
}

main();