import * as math from 'mathjs';

class DataMutation {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    apply_mutation(mutation_function: (data: number[]) => number[]): number[] {
        this.data = mutation_function(this.data);
        return this.data;
    }
}

class FinancialModel {
    initial_price: number;
    volatility: number;
    risk_free_rate: number;
    time_steps: number;
    simulations: number;

    constructor(initial_price: number, volatility: number, risk_free_rate: number, time_steps: number, simulations: number) {
        this.initial_price = initial_price;
        this.volatility = volatility;
        this.risk_free_rate = risk_free_rate;
        this.time_steps = time_steps;
        this.simulations = simulations;
    }

    simulate_paths(): number[][] {
        const dt = 1 / this.time_steps;
        const drift = (this.risk_free_rate - 0.5 * this.volatility ** 2) * dt;
        const diffusion = this.volatility * math.sqrt(dt);
        const paths: number[][] = Array.from({ length: this.time_steps + 1 }, () => Array(this.simulations).fill(0));
        paths[0].fill(this.initial_price);
        for (let t = 1; t <= this.time_steps; t++) {
            const rand = Array.from({ length: this.simulations }, () => math.randomNormal());
            paths[t] = paths[t - 1].map((value, index) => value * math.exp(drift + diffusion * rand[index]));
        }
        return paths;
    }

    calculate_payoff(strike_price: number, option_type: 'call' | 'put' = 'call'): number[] {
        const paths = this.simulate_paths();
        let payoff: number[];
        if (option_type === 'call') {
            payoff = paths[paths.length - 1].map(value => math.max(value - strike_price, 0));
        } else if (option_type === 'put') {
            payoff = paths[paths.length - 1].map(value => math.max(strike_price - value, 0));
        }
        return payoff;
    }

    price_option(strike_price: number, option_type: 'call' | 'put' = 'call'): number {
        const payoff = this.calculate_payoff(strike_price, option_type);
        const option_price = math.exp(-this.risk_free_rate * this.time_steps) * math.mean(payoff);
        return option_price;
    }
}

function main() {
    const data = Array.from({ length: 100 }, () => math.random());
    const data_mutator = new DataMutation(data);
    const mutated_data = data_mutator.apply_mutation((x: number[]) => x.map(value => value * 2));
    const financial_model = new FinancialModel(mutated_data[0], 0.2, 0.05, 252, 10000);
    const option_price = financial_model.price_option(100, 'call');
    console.log(option_price);
}

main();