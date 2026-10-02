import * as random from 'mathjs';

function simulate_paths(S0: number, mu: number, sigma: number, T: number, N: number, M: number): number[][] {
    const dt = T / N;
    const paths: number[][] = Array.from({ length: M }, () => [S0]);
    for (let t = 1; t <= N; t++) {
        for (let i = 0; i < M; i++) {
            const z = random.normal(0, 1);
            paths[i].push(paths[i][paths[i].length - 1] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z));
        }
    }
    return paths;
}

function calculate_payoffs(paths: number[][], K: number, T: number, r: number, type: string = 'call'): number[] {
    const payoffs: number[] = [];
    for (const path of paths) {
        const ST = path[path.length - 1];
        let payoff: number;
        if (type === 'call') {
            payoff = Math.max(0, ST - K);
        } else {
            payoff = Math.max(0, K - ST);
        }
        payoffs.push(payoff * Math.exp(-r * T));
    }
    return payoffs;
}

function monte_carlo_pricing(S0: number, K: number, T: number, r: number, sigma: number, M: number): number {
    const paths = simulate_paths(S0, r, sigma, T, 100, M);
    const payoffs = calculate_payoffs(paths, K, T, r);
    return payoffs.reduce((sum, payoff) => sum + payoff, 0) / M;
}

function main(): void {
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