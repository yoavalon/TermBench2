const { randomNormal } = require('mathjs');

function simulatePaths(S0, T, r, sigma, N, M) {
    const dt = T / N;
    const S = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    S[0] = Array(M).fill(S0);
    for (let t = 1; t <= N; t++) {
        const Z = randomNormal(M).map(z => z * Math.sqrt(dt));
        S[t] = S[t - 1].map((s, i) => s * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Z[i]));
    }
    return S;
}

function optionPrice(S, K, T, r, type = 'call') {
    let payoff;
    if (type === 'call') {
        payoff = S[S.length - 1].map(s => Math.max(s - K, 0));
    } else {
        payoff = S[S.length - 1].map(s => Math.max(K - s, 0));
    }
    const price = Math.exp(-r * T) * payoff.reduce((a, b) => a + b, 0) / M;
    return price;
}

function main() {
    const [S0, K, T, r, sigma, N, M] = [100, 100, 1, 0.05, 0.2, 100, 10000];
    const S = simulatePaths(S0, T, r, sigma, N, M);
    const price = optionPrice(S, K, T, r);
    console.log(price);
}

main();