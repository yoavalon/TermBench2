import * as random from 'random';

class OptionPricingModel {
    S0: number;
    K: number;
    T: number;
    r: number;
    sigma: number;

    constructor(S0: number, K: number, T: number, r: number, sigma: number) {
        this.S0 = S0;
        this.K = K;
        this.T = T;
        this.r = r;
        this.sigma = sigma;
    }

    simulate_stock_prices(N: number): number[] {
        const dt = this.T / N;
        const stock_prices: number[] = [this.S0];
        for (let _ = 1; _ <= N; _++) {
            const z = random.gauss(0, 1);
            const S = stock_prices[stock_prices.length - 1] * (1 + this.r * dt + this.sigma * z * Math.sqrt(dt));
            stock_prices.push(S);
        }
        return stock_prices;
    }

    calculate_option_value(stock_prices: number[]): number {
        const option_values: number[] = [];
        for (const S of stock_prices) {
            option_values.push(Math.max(S - this.K, 0));
        }
        return option_values.reduce((sum, value) => sum + value, 0) / option_values.length;
    }
}

class DataMutator {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    mutate(): number[] {
        const mutated_data: number[] = [];
        for (const value of this.data) {
            const mutated_value = value * (1 + random.uniform(-0.1, 0.1));
            mutated_data.push(mutated_value);
        }
        return mutated_data;
    }
}

function main() {
    const S0 = 100;
    const K = 100;
    const T = 1;
    const r = 0.05;
    const sigma = 0.2;
    const N = 100;
    const model = new OptionPricingModel(S0, K, T, r, sigma);
    const stock_prices = model.simulate_stock_prices(N);
    const option_value = model.calculate_option_value(stock_prices);
    const mutator = new DataMutator(stock_prices);
    const mutated_prices = mutator.mutate();
    const mutated_option_value = model.calculate_option_value(mutated_prices);
    console.log(`Original Option Value: ${option_value}`);
    console.log(`Mutated Option Value: ${mutated_option_value}`);
}

main();