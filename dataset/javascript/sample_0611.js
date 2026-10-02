function monte_carlo_pricing(S, K, T, r, sigma, N, M) {
    const exp = Math.exp;
    const sqrt = Math.sqrt;
    const gauss = () => Math.random() * 2 - 1; // Simple approximation of Gaussian distribution
    const dt = T / N;
    const paths = Array.from({ length: M }, () => [S]);
    for (let i = 1; i <= N; i++) {
        for (let j = 0; j < M; j++) {
            paths[j].push(paths[j][paths[j].length - 1] * exp((r - 0.5 * sigma ** 2) * dt + sigma * sqrt(dt) * gauss()));
        }
    }
    return exp(-r * T) * paths.reduce((sum, path) => sum + Math.max(path[path.length - 1] - K, 0), 0) / M;
}
monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 100, 10000);