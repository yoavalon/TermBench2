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
        const S = Array.from({ length: this.M }, () => Array(this.N + 1).fill(0));
        S.forEach(row => row[0] = this.S0);
        for (let t = 1; t <= this.N; t++) {
            const Z = Array.from({ length: this.M }, () => Math.random() * 2 - 1);
            S.forEach((row, i) => row[t] = row[t - 1] * Math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * Math.sqrt(dt) * Z[i]));
        }
        return S;
    }

    calculate_option_price() {
        const S = this.simulate_paths();
        const payoff = S.map(row => Math.max(row[row.length - 1] - this.K, 0));
        const option_price = Math.exp(-this.r * this.T) * payoff.reduce((sum, val) => sum + val, 0) / this.M;
        return option_price;
    }
}

function main() {
    const S0 = 100.0;
    const K = 100.0;
    const T = 1.0;
    const r = 0.05;
    const sigma = 0.2;
    const N = 252;
    const M = 10000;
    const model = new FinancialModel(S0, K, T, r, sigma, N, M);
    const price = model.calculate_option_price();
    console.log(`Option price: ${price.toFixed(4)}`);
}

main();