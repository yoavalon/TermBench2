import * as math from 'mathjs';
import * as random from 'random-js';

class OptionModel {
    S0: number;
    K: number;
    T: number;
    r: number;
    sigma: number;
    n_simulations: number;

    constructor(S0: number, K: number, T: number, r: number, sigma: number, n_simulations: number) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
        this.n_simulations = n_simulations;
    }

    simulate(): number[] {
        let option_values: number[] = [];
        for (let _ = 0; _ < this.n_simulations; _++) {
            let S_T = this.S0 * math.exp((this.r - 0.5 * math.pow(this.sigma, 2)) * this.T + this.sigma * math.sqrt(this.T) * random.gaussian(random, 0, 1));
            option_values.push(math.max(0, S_T - this.K));
        }
        return option_values;
    }
}

class PricingEngine {
    model: OptionModel;

    constructor(model: OptionModel) {
        this.model = model;
    }

    calculate_price(): number {
        let option_values = this.model.simulate();
        return math.sum(option_values) / option_values.length;
    }
}

class SimulationController {
    pricing_engine: PricingEngine;

    constructor(pricing_engine: PricingEngine) {
        this.pricing_engine = pricing_engine;
    }

    run(): void {
        while (true) {
            let price = this.pricing_engine.calculate_price();
            console.log(`Option price: ${price}`);
        }
    }
}

function main(): void {
    let S0 = 100;
    let K = 100;
    let T = 1;
    let r = 0.05;
    let sigma = 0.2;
    let n_simulations = 1000;
    let model = new OptionModel(S0, K, T, r, sigma, n_simulations);
    let pricing_engine = new PricingEngine(model);
    let controller = new SimulationController(pricing_engine);
    controller.run();
}

main();