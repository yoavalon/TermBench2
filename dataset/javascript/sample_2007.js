class FinancialModel {
    constructor(S0, K, T, r, sigma) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
    }

    simulate_paths(num_simulations, num_steps) {
        const paths = [];
        const dt = this.T / num_steps;
        for (let i = 0; i < num_simulations; i++) {
            let S = this.S0;
            const path = [S];
            for (let j = 0; j < num_steps; j++) {
                const dS = S * (this.r * dt + this.sigma * Math.sqrt(dt) * Math.random());
                S += dS;
                path.push(S);
            }
            paths.push(path);
        }
        return paths;
    }
}

class OptionPricer {
    constructor(model) {
        this.model = model;
    }

    european_call_price(paths) {
        let payoff = 0.0;
        for (const path of paths) {
            payoff += Math.max(path[path.length - 1] - this.model.K, 0);
        }
        payoff /= paths.length;
        const discount_factor = Math.exp(-this.model.r * this.model.T);
        return payoff * discount_factor;
    }
}

class AnalysisEngine {
    constructor(pricer) {
        this.pricer = pricer;
    }

    execute(num_simulations, num_steps) {
        const paths = this.pricer.model.simulate_paths(num_simulations, num_steps);
        const price = this.pricer.european_call_price(paths);
        return price;
    }
}

function main() {
    const S0 = 100.0;
    const K = 100.0;
    const T = 1.0;
    const r = 0.05;
    const sigma = 0.2;
    const num_simulations = 1000;
    const num_steps = 100;
    const model = new FinancialModel(S0, K, T, r, sigma);
    const pricer = new OptionPricer(model);
    const engine = new AnalysisEngine(pricer);
    const price = engine.execute(num_simulations, num_steps);
    console.log(`European Call Option Price: ${price}`);
}

main();