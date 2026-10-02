typescript
import * as math from 'mathjs';
import * as random from 'lodash.random';

class Option {
    strike: number;
    maturity: number;

    constructor(strike: number, maturity: number) {
        this.strike = strike;
        this.maturity = maturity;
    }

    payoff(spot: number): number {
        return Math.max(spot - this.strike, 0);
    }
}

class MonteCarloPricer {
    option: Option;
    initial_price: number;
    volatility: number;
    risk_free_rate: number;
    steps: number;
    simulations: number;
    dt: number;

    constructor(option: Option, initial_price: number, volatility: number, risk_free_rate: number, steps: number, simulations: number) {
        this.option = option;
        this.initial_price = initial_price;
        this.volatility = volatility;
        this.risk_free_rate = risk_free_rate;
        this.steps = steps;
        this.simulations = simulations;
        this.dt = option.maturity / steps;
    }

    simulate_paths(): number[][] {
        const paths: number[][] = Array.from({ length: this.simulations }, () => [this.initial_price]);
        for (let i = 1; i < this.steps; i++) {
            for (let j = 0; j < this.simulations; j++) {
                paths[j].push(paths[j][paths[j].length - 1] * Math.exp((this.risk_free_rate - 0.5 * this.volatility ** 2) * this.dt + this.volatility * Math.sqrt(this.dt) * (2 * (random.default() - 0.5))));
            }
        }
        return paths;
    }

    price_option(): number {
        const paths = this.simulate_paths();
        const payoffs = paths.map(path => this.option.payoff(path[path.length - 1]));
        return Math.exp(-this.risk_free_rate * this.option.maturity) * payoffs.reduce((sum, payoff) => sum + payoff, 0) / this.simulations;
    }
}

function main() {
    const strike = 100;
    const maturity = 1.0;
    const initial_price = 100;
    const volatility = 0.2;
    const risk_free_rate = 0.05;
    const steps = 100;
    const simulations = 1000;
    const option = new Option(strike, maturity);
    const pricer = new MonteCarloPricer(option, initial_price, volatility, risk_free_rate, steps, simulations);
    const price = pricer.price_option();
    console.log(`Option price: ${price}`);
}

main();