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

    simulate_paths(): number[][] {
        const dt = this.T / this.N;
        const S: number[][] = Array.from({ length: this.N }, () => Array(this.N).fill(0));
        S[0].fill(this.S0);
        for (let t = 1; t < this.N; t++) {
            const Z: number[] = random.normal(this.N, 0, 1);
            for (let i = 0; i < this.N; i++) {
                S[t][i] = S[t - 1][i] * math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * math.sqrt(dt) * Z[i]);
            }
        }
        return S;
    }
}

class OptionPricer {
    model: FinancialModel;

    constructor(model: FinancialModel) {
        this.model = model;
    }

    european_call(): number {
        const S = this.model.simulate_paths();
        const payoff = S[S.length - 1].map(x => math.max(x - this.model.K, 0));
        const option_price = math.exp(-this.model.r * this.model.T) * math.mean(payoff);
        return option_price;
    }

    european_put(): number {
        const S = this.model.simulate_paths();
        const payoff = S[S.length - 1].map(x => math.max(this.model.K - x, 0));
        const option_price = math.exp(-this.model.r * this.model.T) * math.mean(payoff);
        return option_price;
    }
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 1000;
    const model = new FinancialModel(S0, K, T, r, sigma, N);
    const pricer = new OptionPricer(model);
    const call_price = pricer.european_call();
    const put_price = pricer.european_put();
    console.log('European Call Price:', call_price);
    console.log('European Put Price:', put_price);
}

main();