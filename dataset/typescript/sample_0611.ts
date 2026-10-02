function monte_carlo_pricing(S: number, K: number, T: number, r: number, sigma: number, N: number, M: number): number {
    const exp = Math.exp;
    const sqrt = Math.sqrt;
    const gauss = (mu: number, sigma: number): number => {
        let u = 0, v = 0;
        while (u === 0) u = Math.random(); // Converting [0,1) to (0,1)
        while (v === 0) v = Math.random();
        return mu + sigma * sqrt(-2.0 * Math.log(u)) * Math.cos(2.0 * Math.PI * v);
    };

    const dt = T / N;
    const paths: number[][] = Array.from({ length: M }, () => [S]);
    for (let i = 1; i <= N; i++) {
        for (let j = 0; j < M; j++) {
            paths[j].push(paths[j][paths[j].length - 1] * exp((r - 0.5 * sigma ** 2) * dt + sigma * sqrt(dt) * gauss(0, 1)));
        }
    }
    return exp(-r * T) * paths.reduce((sum, path) => sum + Math.max(path[path.length - 1] - K, 0), 0) / M;
}

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 100, 10000);