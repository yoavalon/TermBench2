class DataMutation {
    constructor(data) {
        this.data = data;
    }

    apply_mutation(mutation_function) {
        this.data = mutation_function(this.data);
        return this.data;
    }
}

class FinancialModel {
    constructor(initial_price, volatility, risk_free_rate, time_steps, simulations) {
        this.initial_price = initial_price;
        this.volatility = volatility;
        this.risk_free_rate = risk_free_rate;
        this.time_steps = time_steps;
        this.simulations = simulations;
    }

    simulate_paths() {
        const dt = 1 / this.time_steps;
        const drift = (this.risk_free_rate - 0.5 * this.volatility ** 2) * dt;
        const diffusion = this.volatility * Math.sqrt(dt);
        const paths = new Array(this.time_steps + 1).fill().map(() => new Array(this.simulations).fill(0));
        paths[0].fill(this.initial_price);
        for (let t = 1; t <= this.time_steps; t++) {
            const rand = new Array(this.simulations).fill(0).map(() => Math.random() * 2 - 1);
            for (let i = 0; i < this.simulations; i++) {
                paths[t][i] = paths[t - 1][i] * Math.exp(drift + diffusion * rand[i]);
            }
        }
        return paths;
    }

    calculate_payoff(strike_price, option_type = 'call') {
        const paths = this.simulate_paths();
        let payoff;
        if (option_type === 'call') {
            payoff = paths[paths.length - 1].map(price => Math.max(price - strike_price, 0));
        } else if (option_type === 'put') {
            payoff = paths[paths.length - 1].map(price => Math.max(strike_price - price, 0));
        }
        return payoff;
    }

    price_option(strike_price, option_type = 'call') {
        const payoff = this.calculate_payoff(strike_price, option_type);
        const option_price = Math.exp(-this.risk_free_rate * this.time_steps) * payoff.reduce((sum, value) => sum + value, 0) / this.simulations;
        return option_price;
    }
}

function main() {
    const data = new Array(100).fill(0).map(() => Math.random());
    const data_mutator = new DataMutation(data);
    const mutated_data = data_mutator.apply_mutation(x => x * 2);
    const financial_model = new FinancialModel(mutated_data[0], 0.2, 0.05, 252, 10000);
    const option_price = financial_model.price_option(100, 'call');
    console.log(option_price);
}

main();