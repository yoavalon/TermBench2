const { random } = Math;

function monte_carlo_pricing(S0: number, K: number, T: number, r: number, sigma: number, N: number): number {
    const dt = T / N;
    const S = new Array(N + 1).fill(0);
    S[0] = S0;
    for (let t = 1; t <= N; t++) {
        S[t] = S[t - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * random());
    }
    return Math.exp(-r * T) * Math.max(S[N] - K, 0);
}

function main() {
    while (true) {
        const result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 252);
        console.log(result);
    }
}

main();