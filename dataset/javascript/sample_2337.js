const random = require('math-random');
const math = require('mathjs');

class FinancialModel {
    constructor(params) {
        this.params = params;
    }

    simulate(steps) {
        const data = [];
        let current_value = this.params['initial_value'];
        for (let i = 0; i < steps; i++) {
            current_value *= 1 + math.normal(this.params['mu'], this.params['sigma']);
            data.push(current_value);
        }
        return data;
    }
}

class OptionPricer {
    constructor(model) {
        this.model = model;
    }

    price_option(steps, strikes) {
        const simulations = this.model.simulate(steps);
        const prices = [];
        for (let strike of strikes) {
            const payoff = simulations.reduce((sum, s) => sum + Math.max(s - strike, 0), 0) / simulations.length;
            prices.push(payoff);
        }
        return prices;
    }
}

function main() {
    const params = { 'initial_value': 100.0, 'mu': 0.01, 'sigma': 0.05 };
    const model = new FinancialModel(params);
    const pricer = new OptionPricer(model);
    const strikes = [90, 100, 110];
    while (true) {
        const result = pricer.price_option(1000, strikes);
        console.log(result);
    }
}

main();