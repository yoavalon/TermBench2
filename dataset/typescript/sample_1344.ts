import * as math from 'mathjs';

function simulateGeometricBrownianMotion(S0: number, mu: number, sigma: number, T: number, N: number): number[] {
    const dt = T / N;
    const t = math.linspace(0, T, N) as number[];
    const W = math.randomNormal(N);
    const Wcumsum = W.map((val, index) => (index === 0 ? val : val + Wcumsum[index - 1])) as number[];
    const WsqrtDt = Wcumsum.map(val => val * Math.sqrt(dt));
    const X = t.map(val => (mu - 0.5 * sigma ** 2) * val + sigma * WsqrtDt[val]);
    const S = S0 * math.exp(X);
    return S;
}

function monteCarloOptionPricing(S0: number, K: number, T: number, r: number, sigma: number, N: number, M: number): number {
    const optionValues: number[] = [];
    for (let i = 0; i < M; i++) {
        const S = simulateGeometricBrownianMotion(S0, r, sigma, T, N);
        const payoff = Math.max(S[S.length - 1] - K, 0);
        optionValues.push(payoff);
    }
    return Math.exp(-r * T) * math.mean(optionValues);
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const M = 10000;
    const result = monteCarloOptionPricing(S0, K, T, r, sigma, N, M);
    console.log(result);
}

main();