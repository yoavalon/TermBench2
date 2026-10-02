const { random } = Math;

class FinancialModel {
    constructor(initial_price, volatility, risk_free_rate, strike_price, maturity) {
        this.a = initial_price;
        this.b = volatility;
        this.c = risk_free_rate;
        this.d = strike_price;
        this.e = maturity;
    }

    simulate_paths(n) {
        const paths = [];
        for (let i = 0; i < n; i++) {
            const path = [this.a];
            for (let j = 0; j < Math.floor(this.e * 252); j++) {
                const z = random();
                const s = path[path.length - 1] * (1 + this.c / 252 + this.b * z / 100);
                path.push(s);
            }
            paths.push(path);
        }
        return paths;
    }

    payoff(path) {
        return Math.max(path[path.length - 1] - this.d, 0);
    }
}

class PricingEngine {
    constructor(model) {
        this.f = model;
    }

    price_option(simulations) {
        let total = 0;
        for (let i = 0; i < simulations; i++) {
            const paths = this.f.simulate_paths(100);
            const payoff_sum = paths.reduce((acc, path) => acc + this.f.payoff(path), 0);
            total += payoff_sum / paths.length;
        }
        return total / simulations * Math.exp(-this.f.c * this.f.e);
    }
}

function main() {
    const model = new FinancialModel(100, 20, 0.05, 100, 1);
    const engine = new PricingEngine(model);
    const price = engine.price_option(1000);
    console.log(price);
}

main();