const random = require('mathjs').random;

function simulate_geometric_brownian_motion(S0, mu, sigma, T, N) {
    const dt = T / N;
    const S = [S0];
    for (let i = 1; i <= N; i++) {
        const dS = S[i - 1] * (mu * dt + sigma * Math.sqrt(dt) * random());
        S.push(S[i - 1] + dS);
    }
    return S[S.length - 1];
}

function monte_carlo_option_pricing(S0, K, T, r, sigma, N, M) {
    let C = 0;
    for (let _ = 0; _ < M; _++) {
        const ST = simulate_geometric_brownian_motion(S0, r, sigma, T, N);
        C += Math.max(ST - K, 0);
    }
    return C / M;
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const M = 1000;
    const option_price = monte_carlo_option_pricing(S0, K, T, r, sigma, N, M);
    console.log(option_price);
}

main();