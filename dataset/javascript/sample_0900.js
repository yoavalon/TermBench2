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
        let paths = [];
        for (let i = 0; i < this.N; i++) {
            let path = [this.S0];
            for (let j = 1; j < this.T * 252; j++) {
                let S_next = path[path.length - 1] * (1 + Math.random() * this.sigma * Math.sqrt(252 ** -1));
                path.push(S_next);
            }
            paths.push(path);
        }
        return paths;
    }

    calculate_payoffs(paths) {
        let payoffs = [];
        for (let path of paths) {
            let payoff = Math.max(0, path[path.length - 1] - this.K);
            payoffs.push(payoff);
        }
        return payoffs;
    }
}

class OptionPricer {
    constructor(model) {
        this.model = model;
    }

    price_option() {
        let paths = this.model.simulate_paths();
        let payoffs = this.model.calculate_payoffs(paths);
        let discounted_payoffs = payoffs.map(p => p * Math.exp(-this.model.r));
        return discounted_payoffs.reduce((acc, val) => acc + val, 0) / discounted_payoffs.length;
    }
}

function main() {
    let S0 = 100;
    let K = 100;
    let T = 1;
    let r = 0.05;
    let sigma = 0.2;
    let N = 10000;
    let model = new FinancialModel(S0, K, T, r, sigma, N);
    let pricer = new OptionPricer(model);
    let option_price = pricer.price_option();
    console.log(`Option Price: ${option_price}`);
}

main();