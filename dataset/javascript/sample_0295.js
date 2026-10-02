const { randomNormal } = require('mathjs');

class FinancialModel {
    constructor(S0, K, T, r, sigma, N) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
        this.dt = T / N;
    }

    simulate_paths() {
        const paths = Array.from({ length: this.N + 1 }, () => Array(this.S0.length).fill(0));
        paths[0] = this.S0;
        for (let t = 1; t <= this.N; t++) {
            const z = randomNormal(this.S0.length);
            paths[t] = paths[t - 1].map((S, i) => S * Math.exp((this.r - 0.5 * this.sigma ** 2) * this.dt + this.sigma * Math.sqrt(this.dt) * z[i]));
        }
        return paths;
    }

    payoff(paths) {
        const payoff = paths[paths.length - 1].map(S => Math.max(S - this.K, 0));
        return payoff;
    }
}

class OptionPricer {
    constructor(financial_model, M) {
        this.financial_model = financial_model;
        this.M = M;
    }

    price_option() {
        const payoffs = Array(this.M).fill(0);
        for (let i = 0; i < this.M; i++) {
            const paths = this.financial_model.simulate_paths();
            const payoff = this.financial_model.payoff(paths);
            payoffs[i] = payoff.reduce((acc, val) => acc + val, 0) / payoff.length;
        }
        const option_price = Math.exp(-this.financial_model.r * this.financial_model.T) * (payoffs.reduce((acc, val) => acc + val, 0) / payoffs.length);
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