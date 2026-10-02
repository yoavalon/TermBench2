import * as math from 'mathjs';

function generate_paths(S0: number, mu: number, sigma: number, T: number, N: number, M: number): number[][] {
    const dt = T / N;
    const S = Array.from({ length: N + 1 }, () => Array(M).fill(0));
    S[0] = Array(M).fill(S0);
    for (let t = 1; t <= N; t++) {
        for (let i = 0; i < M; i++) {
            S[t][i] = S[t - 1][i] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * math.randomNormal());
        }
    }
    return S;
}

function option_price(paths: number[][], K: number, r: number, T: number, payoff: (S: number[], K: number) => number[]): number {
    const discounted_payoffs = paths[paths.length - 1].map(S => Math.exp(-r * T) * payoff([S], K)[0]);
    return discounted_payoffs.reduce((acc, val) => acc + val, 0) / discounted_payoffs.length;
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

    function european_call(S: number[], K: number): number[] {
        return S.map(S => Math.max(S - K, 0));
    }
    const paths = generate_paths(S0, mu, sigma, T, N, M);
    const call_price = option_price(paths, K, r, T, european_call);
    console.log(call_price);
}

main();