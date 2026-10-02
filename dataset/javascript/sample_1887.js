const { random, exp, sqrt, max, mean } = Math;

function monte_carlo_option_pricing(S, K, T, r, sigma, N) {
    const dt = T / N;
    const S_T = Array.from({ length: N }, () =>
        S * exp((r - 0.5 * sigma ** 2) * dt + sigma * sqrt(dt) * random())
    );
    return exp(-r * T) * mean(S_T.map(x => max(x - K, 0)));
}

function mean(arr) {
    return arr.reduce((a, b) => a + b, 0) / arr.length;
}

monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 10000).then(console.log);