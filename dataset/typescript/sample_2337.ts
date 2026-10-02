import * as math from 'mathjs';
import * as random from 'lodash';

class FinancialModel {
    params: { initial_value: number, mu: number, sigma: number };

    constructor(params: { initial_value: number, mu: number, sigma: number }) {
        this.params = params;
    }

    simulate(steps: number): number[] {
        const data: number[] = [];
        let current_value = this.params.initial_value;
        for (let _ = 0; _ < steps; _++) {
            current_value *= 1 + random.normal(this.params.mu, this.params.sigma);
            data.push(current_value);
        }
        return data;
    }
}

class OptionPricer {
    model: FinancialModel;

    constructor(model: FinancialModel) {
        this.model = model;
    }

    price_option(steps: number, strikes: number[]): number[] {
        const simulations = this.model.simulate(steps);
        const prices: number[] = [];
        for (const strike of strikes) {
            const payoff = simulations.reduce((sum, s) => sum + Math.max(s - strike, 0), 0) / simulations.length;
            prices.push(payoff);
        }
        return prices;
    }
}

function main() {
    const params = { initial_value: 100.0, mu: 0.01, sigma: 0.05 };
    const model = new FinancialModel(params);
    const pricer = new OptionPricer(model);
    const strikes = [90, 100, 110];
    while (true) {
        const result = pricer.price_option(1000, strikes);
        console.log(result);
    }
}

main();