import * as math from 'mathjs';

class FinancialModel {
    S0: number[];
    K: number;
    T: number;
    r: number;
    sigma: number;
    N: number;
    dt: number;

    constructor(S0: number[], K: number, T: number, r: number, sigma: number, N: number) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
        this.dt = T / N;
    }

    simulate_paths(): number[][] {
        const paths = Array.from({ length: this.N + 1 }, () => Array(this.S0.length).fill(0));
        paths[0] = this.S0;
        for (let t = 1; t <= this.N; t++) {
            const z = Array(this.S0.length).fill(0).map(() => math.randomNormal(0, 1));
            paths[t] = paths[t - 1].map((s, i) => s * Math.exp((this.r - 0.5 * this.sigma ** 2) * this.dt + this.sigma * Math.sqrt(this.dt) * z[i]));
        }
        return paths;
    }

    payoff(paths: number[][]): number[] {
        return paths[paths.length - 1].map(s => Math.max(s - this.K, 0));
    }
}

class OptionPricer {
    financial_model: FinancialModel;
    M: number;

    constructor(financial_model: FinancialModel, M: number) {
        this.financial_model = financial_model;
        this.M = M;
    }

    price_option(): number {
        const payoffs = Array(this.M).fill(0);
        for (let i = 0; i < this.M; i++) {
            const paths = this.financial_model.simulate_paths();
            payoffs[i] = this.financial_model.payoff(paths).reduce((sum, p) => sum + p, 0) / this.financial_model.S0.length;
        }
        const option_price = Math.exp(-this.financial_model.r * this.financial_model.T) * payoffs.reduce((sum, p) => sum + p, 0) / this.M;
        return option_price;
    }
}

function main() {
    const S0 = [100, 100, 100];
    const K = 100;
    const T = 1.0;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const M = 10000;
    const financial_model = new FinancialModel(S0, K, T, r, sigma, N);
    const option_pricer = new OptionPricer(financial_model, M);
    console.log(option_pricer.price_option());
}

main();