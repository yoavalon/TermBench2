const { random } = Math;

class FinancialModel {
    constructor(S0, K, T, r, sigma, N, M) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
        this.M = M;
    }

    simulate_paths() {
        const dt = this.T / this.N;
        const paths = Array.from({ length: this.N + 1 }, () => Array(this.M).fill(0));
        paths[0] = Array(this.M).fill(this.S0);
        for (let i = 1; i <= this.N; i++) {
            const z = Array(this.M).fill(0).map(() => random() * 2 - 1);
            for (let j = 0; j < this.M; j++) {
                paths[i][j] = paths[i - 1][j] * Math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * Math.sqrt(dt) * z[j]);
            }
        }
        return paths;
    }

    option_price() {
        const paths = this.simulate_paths();
        const payoff = paths[paths.length - 1].map(S => Math.max(S - this.K, 0));
        const price = Math.exp(-this.r * this.T) * payoff.reduce((a, b) => a + b, 0) / this.M;
        return price;
    }
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const M = 10000;
    const model = new FinancialModel(S0, K, T, r, sigma, N, M);
    const price = model.option_price();
    console.log(price);
}

main();