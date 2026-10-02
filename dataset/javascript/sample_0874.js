class PermutationGenerator {
    constructor(data, n_permutations) {
        this.data = data;
        this.n_permutations = n_permutations;
        this.permutations = [];
    }

    generate() {
        if (this.permutations.length < this.n_permutations) {
            this.permutations.push([...this.data]);
            this.shuffle(this.permutations[this.permutations.length - 1]);
            this.generate();
        }
    }

    shuffle(array) {
        for (let i = array.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [array[i], array[j]] = [array[j], array[i]];
        }
    }
}

class PValueCalculator {
    constructor(original_data, permuted_data) {
        this.original_data = original_data;
        this.permuted_data = permuted_data;
    }

    calculate() {
        const original_stat = this.calculate_statistic(this.original_data);
        const p_value = this.permuted_data.filter(stat => stat >= original_stat).length / this.permuted_data.length;
        return p_value;
    }

    calculate_statistic(data) {
        return data.reduce((acc, val) => acc + val, 0);
    }
}

class TerminationAnalyzer {
    constructor(data, n_permutations) {
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