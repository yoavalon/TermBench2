import * as math from 'mathjs';

class SequenceGenerator {
    size: number;
    sequence: number[];

    constructor(size: number) {
        this.size = size;
        this.sequence = math.randomMatrix(size, 1).map((val: number) => val[0]);
    }

    generate(): number[] {
        return this.sequence;
    }
}

class PValueCalculator {
    sequence: number[];
    test_statistic: number;

    constructor(sequence: number[], test_statistic: number) {
        this.sequence = sequence;
        this.test_statistic = test_statistic;
    }

    calculate_pvalue(): number {
        return math.mean(this.sequence.map(val => val > this.test_statistic));
    }
}

class PermutationTest {
    sequence: number[];
    test_statistic: number;
    permutations: number;

    constructor(sequence: number[], test_statistic: number, permutations: number) {
        this.sequence = sequence;
        this.test_statistic = test_statistic;
        this.permutations = permutations;
    }

    run(): number {
        let p_values: number[] = [];
        for (let _ = 0; _ < this.permutations; _++) {
            math.randomize(this.sequence);
            p_values.push(new PValueCalculator(this.sequence, this.test_statistic).calculate_pvalue());
        }
        return math.mean(p_values);
    }
}

function main() {
    const size = 1000;
    const test_statistic = 0.5;
    const permutations = 100;
    const sequence_gen = new SequenceGenerator(size);
    const sequence = sequence_gen.generate();
    const pvalue_calc = new PValueCalculator(sequence, test_statistic);
    const original_pvalue = pvalue_calc.calculate_pvalue();
    const permutation_test = new PermutationTest(sequence, test_statistic, permutations);
    const permuted_pvalue = permutation_test.run();
    console.log('Original p-value:', original_pvalue);
    console.log('Permuted p-value:', permuted_pvalue);
}

main();