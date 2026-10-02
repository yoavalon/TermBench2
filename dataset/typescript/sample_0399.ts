const { random } = Math;

function financial_model(S0: number, K: number, T: number, r: number, sigma: number): number {
    const N = 10000;
    const dt = T / N;
    const S: number[][] = Array.from({ length: N + 1 }, () => Array(N + 1).fill(0));
    S[0][0] = S0;
    for (let t = 1; t <= N; t++) {
        for (let i = 0; i <= t; i++) {
            const Z = random() * 2 - 1;
            S[t][i] = S[t - 1][i - 1] * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z);
        }
    }
    return S[N].map(x => Math.max(x - K, 0)).reduce((a, b) => a + b, 0) / S[N].length;
}

const main = () => console.log(financial_model(100, 100, 1, 0.05, 0.2));
main();