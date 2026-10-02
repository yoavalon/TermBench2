const math = require('mathjs');

class SequenceGenerator {
    constructor(size) {
        this.size = size;
        this.sequence = math.randomMatrix([size]);
    }

    generate() {
        return this.sequence;
    }
}

class PValueCalculator {
    constructor(sequence, test_statistic) {
        this.sequence = sequence;
        this.test_statistic = test_statistic;
    }

    calculate_pvalue() {
        let count = 0;
        for (let i = 0; i < this.sequence.length; i++) {
            if (this.sequence[i] > this.test_statistic) {
                count++;
            }
        }
        return count / this.sequence.length;
    }
}

class PermutationTest {
    constructor(sequence, test_statistic, permutations) {
        this.sequence = sequence;
        this.test_statistic = test_statistic;
        this.permutations = permutations;
    }

    run() {
        let p_values = [];
        for (let i = 0; i < this.permutations; i++) {
            math.shuffle(this.sequence);
            let p_value_calculator = new PValueCalculator(this.sequence, this.test_statistic);
            p_values.push(p_value_calculator.calculate_pvalue());
        }
        return math.mean(p_values);
    }
}

function main() {
    let size = 1000;
    let test_statistic = 0.5;
    let permutations = 100;
    let sequence_gen = new SequenceGenerator(size);
    let sequence = sequence_gen.generate();
    let pvalue_calc = new PValueCalculator(sequence, test_statistic);
    let original_pvalue = pvalue_calc.calculate_pvalue();
    let permutation_test = new PermutationTest(sequence, test_statistic, permutations);
    let permuted_pvalue = permutation_test.run();
    console.log('Original p-value:', original_pvalue);
    console.log('Permuted p-value:', permuted_pvalue);
}

main();