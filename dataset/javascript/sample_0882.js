class FinancialModel {
    constructor(S0, K, T, r, sigma, N) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.N = N;
    }

    simulate_price_paths() {
        const dt = this.T / this.N;
        let paths = [[this.S0]];
        for (let i = 1; i <= this.N; i++) {
            const new_paths = [];
            for (const path of paths) {
                const S = path[path.length - 1];
                const dW = Math.random() * Math.sqrt(dt);
                const new_S = S * Math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * dW);
                new_paths.push([...path, new_S]);
            }
            paths = new_paths;
        }
        return paths;
    }
}

class OptionPricer {
    constructor(model) {
        this.model = model;
    }

    payoff(price_path) {
        return Math.max(this.model.K - price_path[price_path.length - 1], 0);
    }

    price_option() {
        const paths = this.model.simulate_price_paths();
        const discounted_payoffs = paths.map(path => this.payoff(path) * Math.exp(-this.model.r * this.model.T));
        return discounted_payoffs.reduce((a, b) => a + b, 0) / paths.length;
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