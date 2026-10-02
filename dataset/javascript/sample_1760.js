class OptionModel {
    constructor(S0, K, T, r, sigma, n_simulations) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.n_simulations = n_simulations;
    }

    simulate() {
        const option_values = [];
        for (let i = 0; i < this.n_simulations; i++) {
            const S_T = this.S0 * Math.exp((this.r - 0.5 * this.sigma ** 2) * this.T + this.sigma * Math.sqrt(this.T) * Math.random() * 2 - 1);
            option_values.push(Math.max(0, S_T - this.K));
        }
        return option_values;
    }
}

class PricingEngine {
    constructor(model) {
        this.model = model;
    }

    calculate_price() {
        const option_values = this.model.simulate();
        return option_values.reduce((sum, value) => sum + value, 0) / option_values.length;
    }
}

class SimulationController {
    constructor(pricing_engine) {
        this.pricing_engine = pricing_engine;
    }

    run() {
        while (true) {
            const price = this.pricing_engine.calculate_price();
            console.log(`Option price: ${price}`);
        }
    }
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const n_simulations = 1000;
    const model = new OptionModel(S0, K, T, r, sigma, n_simulations);
    const pricing_engine = new PricingEngine(model);
    const controller = new SimulationController(pricing_engine);
    controller.run();
}

main();