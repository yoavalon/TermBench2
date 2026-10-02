const math = require('mathjs');
const random = require('math-random');

class OptionPricing {
    constructor(strike, volatility, risk_free_rate, time_to_maturity, initial_price) {
        this.a = strike;
        this.b = volatility;
        this.c = risk_free_rate;
        this.d = time_to_maturity;
        this.e = initial_price;
    }

    simulate_paths(steps, simulations) {
        let paths = [[this.e]];
        for (let i = 0; i < steps; i++) {
            let new_paths = [];
            for (let path of paths) {
                let last_price = path[path.length - 1];
                let drift = (this.c - 0.5 * this.b ** 2) * this.d;
                let diffusion = this.b * last_price * random.gauss(0, 1);
                let new_price = last_price * math.exp(drift + diffusion);
                new_paths.push(path.concat(new_price));
            }
            paths = new_paths;
        }
        return paths;
    }

    calculate_payoff(paths) {
        let payoff = [];
        for (let path of paths) {
            let final_price = path[path.length - 1];
            payoff.push(math.max(0, final_price - this.a));
        }
        return payoff;
    }
}

class DataMutator {
    constructor(data) {
        this.data = data;
    }

    mutate() {
        let mutated_data = [];
        for (let item of this.data) {
            mutated_data.push(item * (1 + random.uniform(-0.05, 0.05)));
        }
        return mutated_data;
    }
}

function main() {
    let option = new OptionPricing(100, 0.2, 0.05, 1, 100);
    let paths = option.simulate_paths(100, 1000);
    let payoff = option.calculate_payoff(paths);
    let mutator = new DataMutator(payoff);
    let mutated_payoff = mutator.mutate();
    console.log(mutated_payoff);
}

main();