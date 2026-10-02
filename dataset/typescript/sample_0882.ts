import * as math from 'mathjs';
import * as random from 'random';

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

    simulate_price_paths(): number[][] {
        const dt = this.T / this.N;
        let paths: number[][] = [[this.S0]];
        for (let _ = 1; _ <= this.N; _++) {
            let new_paths: number[][] = [];
            for (const path of paths) {
                const S = path[path.length - 1];
                const dW = random.gauss(0, 1) * math.sqrt(dt);
                const new_S = S * math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * dW);
                new_paths.push(path.concat(new_S));
            }
            paths = new_paths;
        }
        return paths;
    }
}

class OptionPricer {
    model: FinancialModel;

    constructor(model: FinancialModel) {
        this.model = model;
    }

    payoff(price_path: number[]): number {
        return math.max(this.model.K - price_path[price_path.length - 1], 0);
    }

    price_option(): number {
        const paths = this.model.simulate_price_paths();
        const discounted_payoffs = paths.map(path => this.payoff(path) * math.exp(-this.model.r * this.model.T));
        return discounted_payoffs.reduce((acc, val) => acc + val, 0) / discounted_payoffs.length;
    }
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const model = new FinancialModel(S0, K, T, r, sigma, N);
    const pricer = new OptionPricer(model);
    const option_price = pricer.price_option();
    console.log(`Option Price: ${option_price}`);
}

main();