import * as math from 'mathjs';
import * as random from 'random';

class FinancialModel {
    S0: number;
    sigma: number;
    r: number;
    K: number;
    T: number;

    constructor(initial_price: number, volatility: number, risk_free_rate: number, strike_price: number, maturity: number) {
        this.S0 = initial_price;
        this.sigma = volatility;
        this.r = risk_free_rate;
        this.K = strike_price;
        this.T = maturity;
    }

    simulate_paths(num_paths: number, num_steps: number): number[][] {
        const dt = this.T / num_steps;
        const paths: number[][] = Array.from({ length: num_paths }, () => [this.S0]);
        for (let _ = 0; _ < num_steps; _++) {
            for (let i = 0; i < num_paths; i++) {
                const Z = random.gaussian(0, 1)();
                const S_next = paths[i][paths[i].length - 1] * math.exp((this.r - 0.5 * this.sigma ** 2) * dt + this.sigma * math.sqrt(dt) * Z);
                paths[i].push(S_next);
            }
        }
        return paths;
    }
}

class OptionPricing {
    model: FinancialModel;
    num_paths: number;
    num_steps: number;

    constructor(model: FinancialModel, num_paths: number, num_steps: number) {
        this.model = model;
        this.num_paths = num_paths;
        this.num_steps = num_steps;
    }

    calculate_option_value(): number {
        const paths = this.model.simulate_paths(this.num_paths, this.num_steps);
        const option_values: number[] = [];
        for (const path of paths) {
            const payoff = Math.max(path[path.length - 1] - this.model.K, 0);
            option_values.push(payoff);
        }
        return option_values.reduce((a, b) => a + b, 0) / this.num_paths * math.exp(-this.model.r * this.model.T);
    }
}

function main() {
    const initial_price = 100;
    const volatility = 0.2;
    const risk_free_rate = 0.05;
    const strike_price = 100;
    const maturity = 1;
    const num_paths = 1000;
    const num_steps = 100;
    const model = new FinancialModel(initial_price, volatility, risk_free_rate, strike_price, maturity);
    const option_pricing = new OptionPricing(model, num_paths, num_steps);
    const value = option_pricing.calculate_option_value();
    console.log(`Option Value: ${value}`);
}

main();