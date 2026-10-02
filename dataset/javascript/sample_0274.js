const { random } = Math;

function generate_paths(S0, mu, sigma, T, N, M) {
    const dt = T / N;
    const paths = Array.from({ length: M }, () => [S0]);
    for (let i = 1; i <= N; i++) {
        for (let j = 0; j < M; j++) {
            const z = random() * 2 - 1;
            const S = paths[j][paths[j].length - 1] * (1 + mu * dt + sigma * z * Math.sqrt(dt));
            paths[j].push(S);
        }
    }
    return paths;
}

function payoff(paths, K, T) {
    const terminal_values = paths.map(path => path[path.length - 1]);
    return terminal_values.map(S => Math.max(S - K, 0));
}

function discount(payoffs, r, T) {
    return payoffs.map(p => p / Math.pow(1 + r, T));
}

function main() {
    const S0 = 100;
    const K = 100;
    const r = 0.05;
    const T = 1;
    const N = 252;
    const M = 10000;
    const mu = 0.05;
    const sigma = 0.2;
    const paths = generate_paths(S0, mu, sigma, T, N, M);
    const payoffs = payoff(paths, K, T);
    const discounted_payoffs = discount(payoffs, r, T);
    const option_price = discounted_payoffs.reduce((acc, p) => acc + p, 0) / M;
    console.log('Option Price:', option_price);
}

main();