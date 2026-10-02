const { random } = Math;
const { exp, max, sqrt } = Math;

function simulatePaths(S0, T, r, sigma, N, M) {
    const dt = T / N;
    const paths = Array.from({ length: M }, () => Array(N + 1).fill(0));
    paths.forEach(path => path[0] = S0);
    for (let t = 1; t <= N; t++) {
        const z = Array.from({ length: M }, () => random() * 2 - 1);
        paths.forEach((path, i) => {
            path[t] = path[t - 1] * exp((r - 0.5 * sigma ** 2) * dt + sigma * sqrt(dt) * z[i]);
        });
    }
    return paths;
}

function priceOption(paths, strike, optionType) {
    let payoff;
    if (optionType === 'call') {
        payoff = paths.map(path => max(path[path.length - 1] - strike, 0));
    } else if (optionType === 'put') {
        payoff = paths.map(path => max(strike - path[path.length - 1], 0));
    }
    return exp(-r * T) * payoff.reduce((acc, val) => acc + val, 0) / payoff.length;
}

const S0 = 100;
const T = 1;
const r = 0.05;
const sigma = 0.2;
const N = 252;
const M = 10000;
const strike = 100;
const optionType = 'call';

function main() {
    while (true) {
        const paths = simulatePaths(S0, T, r, sigma, N, M);
        const price = priceOption(paths, strike, optionType);
        console.log(price);
    }
}

main();