const { random, exp, max, sqrt } = Math;

function generatePaths(S0, mu, sigma, T, N, M) {
    const dt = T / N;
    const S = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    S[0] = S0;
    for (let t = 1; t <= N; t++) {
        for (let i = 0; i < M; i++) {
            S[t][i] = S[t - 1][i] * exp((mu - 0.5 * sigma ** 2) * dt + sigma * sqrt(dt) * random());
        }
    }
    return S;
}

function optionPrice(paths, K, r, T, payoff) {
    const discountedPayoffs = paths[paths.length - 1].map(S => exp(-r * T) * payoff(S, K));
    return discountedPayoffs.reduce((acc, val) => acc + val, 0) / discountedPayoffs.length;
}

function main() {
    const S0 = 100;
    const K = 100;
    const r = 0.05;
    const T = 1;
    const N = 252;
    const M = 10000;
    const sigma = 0.2;
    const mu = 0.1;

    function europeanCall(S, K) {
        return max(S - K, 0);
    }

    const paths = generatePaths(S0, mu, sigma, T, N, M);
    const callPrice = optionPrice(paths, K, r, T, europeanCall);
    console.log(callPrice);
}

main();