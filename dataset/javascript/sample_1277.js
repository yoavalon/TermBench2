const { random } = Math;

function run_model(S, K, T, r, sigma, N, M) {
    const dt = T / N;
    const ST = new Array(M).fill(null).map(() => {
        const path = new Array(N + 1);
        path[0] = S;
        for (let i = 1; i <= N; i++) {
            path[i] = path[i - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * (2 * random() - 1));
        }
        return path;
    });
    const payoff = ST.map(path => Math.max(path[path.length - 1] - K, 0));
    const option_price = Math.exp(-r * T) * payoff.reduce((sum, value) => sum + value, 0) / M;
    return option_price;
}

run_model(100, 100, 1, 0.05, 0.2, 252, 10000);