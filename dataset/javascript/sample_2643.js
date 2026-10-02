const math = require('mathjs');
const random = require('math-random');

class FinancialModel {
    constructor(S0, K, T, r, sigma, N) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
    }

    simulate_paths() {
        const dt = this.T / this.N;
        let paths = [[this.S0]];
        for (let _ = 0; _ < this.N; _++) {
            let new_paths = [];
            for (let path of paths) {
                const S = path[path.length - 1];
                const Z = random.gaussian(0, 1);
                const S_new = S * math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * Z * math.sqrt(dt));
                new_paths.push([...path, S_new]);
            }
            paths = new_paths;
        }
        return paths;
    }

    calculate_payoff(paths) {
        let payoffs = [];
        for (let path of paths) {
            const ST = path[path.length - 1];
            const payoff = math.max(0, ST - this.K);
            payoffs.push(payoff);
        }
        return payoffs;
    }
}

class PricingEngine {
    constructor(model) {
        this.model = model;
    }

    price_option() {
        const paths = this.model.simulate_paths();
        const payoffs = this.model.calculate_payoff(paths);
        const discounted_payoffs = payoffs.map(payoff => payoff * math.exp(-this.model.r * this.model.T));
        const option_price = math.mean(discounted_payoffs);
        return option_price;
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
    const engine = new PricingEngine(model);
    const price = engine.price_option();
    console.log(price);
}

main();