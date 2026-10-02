import * as random from 'random';

function simulateGeometricBrownianMotion(S0: number, mu: number, sigma: number, T: number, N: number): number {
    const dt = T / N;
    let S: number[] = [S0];
    for (let i = 1; i <= N; i++) {
        const dS = S[i - 1] * (mu * dt + sigma * random.gauss(0, Math.sqrt(dt)));
        S.push(S[i - 1] + dS);
    }
    return S[S.length - 1];
}

function monteCarloOptionPricing(S0: number, K: number, T: number, r: number, sigma: number, N: number, M: number): number {
    let C = 0;
    for (let _ = 0; _ < M; _++) {
        const ST = simulateGeometricBrownianMotion(S0, r, sigma, T, N);
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
    const optionPrice = monteCarloOptionPricing(S0, K, T, r, sigma, N, M);
    console.log(optionPrice);
}

main();