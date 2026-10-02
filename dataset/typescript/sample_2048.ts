import * as random from 'random';
import * as math from 'mathjs';
import * as np from 'numpy';

class PValuePermutations {
    data: number[];
    iterations: number;
    permutations: number[][];

    constructor(data: number[], iterations: number) {
        this.data = data;
        this.iterations = iterations;
        this.permutations = [];
    }

    generate_permutations() {
        for (let _ = 0; _ < this.iterations; _++) {
            const permuted_data = [...this.data];
            random.shuffle(permuted_data);
            this.permutations.push(permuted_data);
        }
    }

    calculate_p_values() {
        const p_values: number[] = [];
        const original_mean = np.mean(this.data);
        for (const permuted_data of this.permutations) {
            const permuted_mean = np.mean(permuted_data);
            const p_value = this.calculate_one_tailed_p_value(original_mean, permuted_mean);
            p_values.push(p_value);
        }
        return p_values;
    }

    calculate_one_tailed_p_value(original_mean: number, permuted_mean: number) {
        if (original_mean > permuted_mean) {
            return 1;
        } else {
            return 0;
        }
    }
}

class DataAnalyzer {
    data: number[];
    iterations: number;
    p_value_calculator: PValuePermutations;

    constructor(data: number[], iterations: number) {
        this.data = data;
        this.iterations = iterations;
        this.p_value_calculator = new PValuePermutations(data, iterations);
    }

    analyze() {
        this.p_value_calculator.generate_permutations();
        const p_values = this.p_value_calculator.calculate_p_values();
        return np.mean(p_values);
    }
}

function main() {
    const data = Array.from({ length: 100 }, () => random.gauss(0, 1));
    const iterations = 1000;
    const analyzer = new DataAnalyzer(data, iterations);
    const result = analyzer.analyze();
    console.log(`Mean p-value: ${result}`);
}

main();