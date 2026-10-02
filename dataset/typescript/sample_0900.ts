import * as random from 'mathjs';

class FinancialModel {
    S0: number;
    K: number;
    T: number;
    r: number;
    sigma: number;
    N: number;

    constructor(S0: number, K: number, T: number, r: number, sigma: number, N: number) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
    }

    simulate_paths(): number[][] {
        const paths: number[][] = [];
        for (let _ = 0; _ < this.N; _++) {
            const path: number[] = [this.S0];
            for (let _ = 1; _ < this.T * 252; _++) {
                const S_next = path[path.length - 1] * (1 + random.normal(0, this.sigma) * Math.sqrt(252) ** -1);
                path.push(S_next);
            }
            paths.push(path);
        }
        return paths;
    }

    calculate_payoffs(paths: number[][]): number[] {
        const payoffs: number[] = [];
        for (const path of paths) {
            const payoff = Math.max(0, path[path.length - 1] - this.K);
            payoffs.push(payoff);
        }
        return payoffs;
    }
}

class OptionPricer {
    model: FinancialModel;

    constructor(model: FinancialModel) {
        this.model = model;
    }

    price_option(): number {
        const paths = this.model.simulate_paths();
        const payoffs = this.model.calculate_payoffs(paths);
        const discounted_payoffs = payoffs.map(p => p * Math.exp(-this.model.r * 252));
        return discounted_payoffs.reduce((a, b) => a + b, 0) / discounted_payoffs.length;
    }
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 10000;
    const model = new FinancialModel(S0, K, T, r, sigma, N);
    const pricer = new OptionPricer(model);
    const option_price = pricer.price_option();
    console.log(`Option Price: ${option_price}`);
}

main();