const { random } = Math;
const { exp, sqrt, max } = Math;

function monte_carlo_pricing(S, K, T, r, sigma, N) {
    const dt = T / N;
    const mu = r - 0.5 * sigma ** 2;
    const S_paths = Array.from({ length: N + 1 }, () => Array(S.length).fill(0));
    S_paths[0] = S;
    for (let t = 1; t <= N; t++) {
        const z = S.map(() => random() * 2 - 1);
        S_paths[t] = S_paths[t - 1].map((val, i) => val * exp(mu * dt + sigma * sqrt(dt) * z[i]));
    }
    const payoff = S_paths[N].map(val => max(val - K, 0));
    return exp(-r * T) * payoff.reduce((sum, val) => sum + val, 0) / payoff.length;
}

const main = () => monte_carlo_pricing([100], 100, 1, 0.05, 0.2, 100000);
main();