import * as math from 'mathjs';
import * as random from 'math-random';

class FinancialModel {
    S0: number;
    K: number;
    T: number;
    r: number;
    sigma: number;
    N: number;
    M: number;

    constructor(S0: number, K: number, T: number, r: number, sigma: number, N: number, M: number) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
        this.M = M;
    }

    simulate_paths(): number[][] {
        const dt = this.T / this.N;
        const S: number[][] = Array.from({ length: this.M }, () => Array(this.N + 1).fill(0));
        for (let i = 0; i < this.M; i++) {
            S[i][0] = this.S0;
        }
        for (let t = 1; t <= this.N; t++) {
            const Z = Array.from({ length: this.M }, () => random.normal(0, 1));
            for (let i = 0; i < this.M; i++) {
                S[i][t] = S[i][t - 1] * math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * math.sqrt(dt) * Z[i]);
            }
        }
        return S;
    }

    calculate_option_price(): number {
        const S = this.simulate_paths();
        const payoff = S.map(path => math.max(path[path.length - 1] - this.K, 0));
        const option_price = math.exp(-this.r * this.T) * math.mean(payoff);
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