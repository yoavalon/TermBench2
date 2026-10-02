const { random } = Math;
const { exp, max, sqrt } = Math;

function simulateGeometricBrownianMotion(S0, mu, sigma, T, N) {
    const dt = T / N;
    const t = new Array(N).fill(0).map((_, i) => i * dt);
    const W = new Array(N).fill(0).map(() => random() * 2 - 1).reduce((acc, curr, i) => {
        acc[i] = (acc[i - 1] || 0) + curr;
        return acc;
    }, []).map(w => w * sqrt(dt));
    const X = t.map((ti, i) => (mu - 0.5 * sigma ** 2) * ti + sigma * W[i]);
    const S = X.map(xi => S0 * exp(xi));
    return S;
}

function monteCarloOptionPricing(S0, K, T, r, sigma, N, M) {
    const optionValues = [];
    for (let i = 0; i < M; i++) {
        const S = simulateGeometricBrownianMotion(S0, r, sigma, T, N);
        const payoff = max(S[S.length - 1] - K, 0);
        optionValues.push(payoff);
    }
    return exp(-r * T) * optionValues.reduce((acc, curr) => acc + curr, 0) / M;
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