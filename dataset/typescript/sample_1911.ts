import * as math from 'mathjs';

function simulatePaths(S0: number, T: number, r: number, sigma: number, N: number, M: number): number[][] {
    const dt = T / N;
    const S: number[][] = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    S[0] = Array(M).fill(S0);
    for (let t = 1; t <= N; t++) {
        const Z = Array(M).fill(0).map(() => math.randomNormal());
        for (let i = 0; i < M; i++) {
            S[t][i] = S[t - 1][i] * math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[i]);
        }
    }
    return S;
}

function optionPrice(S: number[][], K: number, T: number, r: number, type: string = 'call'): number {
    let payoff: number[] = [];
    if (type === 'call') {
        payoff = S[S.length - 1].map(x => Math.max(x - K, 0));
    } else {
        payoff = S[S.length - 1].map(x => Math.max(K - x, 0));
    }
    const price = Math.exp(-r * T) * math.mean(payoff);
    return price;
}

function main() {
    const S0 = 100, K = 100, T = 1, r = 0.05, sigma = 0.2, N = 100, M = 10000;
    const S = simulatePaths(S0, T, r, sigma, N, M);
    const price = optionPrice(S, K, T, r);
    console.log(price);
}

main();