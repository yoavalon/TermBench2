import * as math from 'mathjs';
import * as random from 'random';

class OptionPricing {
    a: number;
    b: number;
    c: number;
    d: number;
    e: number;

    constructor(strike: number, volatility: number, risk_free_rate: number, time_to_maturity: number, initial_price: number) {
        this.a = strike;
        this.b = volatility;
        this.c = risk_free_rate;
        this.d = time_to_maturity;
        this.e = initial_price;
    }

    simulate_paths(steps: number, simulations: number): number[][] {
        let paths: number[][] = [[this.e]];
        for (let _ = 0; _ < steps; _++) {
            let new_paths: number[][] = [];
            for (let path of paths) {
                let last_price = path[path.length - 1];
                let drift = (this.c - 0.5 * this.b ** 2) * this.d;
                let diffusion = this.b * last_price * random.gauss(0, 1);
                let new_price = last_price * math.exp(drift + diffusion);
                new_paths.push([...path, new_price]);
            }
            paths = new_paths;
        }
        return paths;
    }

    calculate_payoff(paths: number[][]): number[] {
        let payoff: number[] = [];
        for (let path of paths) {
            let final_price = path[path.length - 1];
            payoff.push(Math.max(0, final_price - this.a));
        }
        return payoff;
    }
}

class DataMutator {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    mutate(): number[] {
        let mutated_data: number[] = [];
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

if (require.main === module) {
    main();
}