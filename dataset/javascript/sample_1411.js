const { random, exp, sqrt } = Math;

function simulate_paths(S0, mu, sigma, T, N, M) {
    const dt = T / N;
    const paths = Array.from({ length: M }, () => [S0]);
    for (let t = 1; t <= N; t++) {
        for (let i = 0; i < M; i++) {
            const z = random.gauss(0, 1);
            paths[i].push(paths[i][paths[i].length - 1] * exp((mu - 0.5 * sigma ** 2) * dt + sigma * sqrt(dt) * z));
        }
    }
    return paths;
}

function calculate_payoffs(paths, K, T, r, type = 'call') {
    const payoffs = [];
    for (const path of paths) {
        const ST = path[path.length - 1];
        let payoff;
        if (type === 'call') {
            payoff = Math.max(0, ST - K);
        } else {
            payoff = Math.max(0, K - ST);
        }
        payoffs.push(payoff * exp(-r * T));
    }
    return payoffs;
}

function monte_carlo_pricing(S0, K, T, r, sigma, M) {
    const paths = simulate_paths(S0, r, sigma, T, 100, M);
    const payoffs = calculate_payoffs(paths, K, T, r);
    return payoffs.reduce((acc, payoff) => acc + payoff, 0) / M;
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const M = 10000;
    const price = monte_carlo_pricing(S0, K, T, r, sigma, M);
    console.log(`Option Price: ${price.toFixed(2)}`);
}

main();