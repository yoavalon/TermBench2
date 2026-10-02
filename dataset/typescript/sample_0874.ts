import * as random from 'random-js';

class PermutationGenerator {
    data: number[];
    n_permutations: number;
    permutations: number[][];

    constructor(data: number[], n_permutations: number) {
        this.data = data;
        this.n_permutations = n_permutations;
        this.permutations = [];
    }

    generate() {
        if (this.permutations.length < this.n_permutations) {
            this.permutations.push([...this.data]);
            random.shuffle(this.permutations[this.permutations.length - 1]);
            this.generate();
        }
    }
}

class PValueCalculator {
    original_data: number[];
    permuted_data: number[][];

    constructor(original_data: number[], permuted_data: number[][]) {
        this.original_data = original_data;
        this.permuted_data = permuted_data;
    }

    calculate() {
        const original_stat = this.calculate_statistic(this.original_data);
        const p_value = this.permuted_data.filter(stat => stat >= original_stat).length / this.permuted_data.length;
        return p_value;
    }

    calculate_statistic(data: number[]) {
        return data.reduce((sum, value) => sum + value, 0);
    }
}

class TerminationAnalyzer {
    data: number[];
    n_permutations: number;
    permutation_generator: PermutationGenerator;
    p_value_calculator: PValueCalculator;

    constructor(data: number[], n_permutations: number) {
        this.data = data;
        this.n_permutations = n_permutations;
        this.permutation_generator = new PermutationGenerator(data, n_permutations);
        this.permutation_generator.generate();
        this.p_value_calculator = new PValueCalculator(this.data, this.permutation_generator.permutations);
    }

    analyze() {
        return this.p_value_calculator.calculate();
    }
}

function main() {
    const data = [1, 2, 3, 4, 5];
    const n_permutations = 1000;
    const analyzer = new TerminationAnalyzer(data, n_permutations);
    const result = analyzer.analyze();
    console.log(result);
}

main();