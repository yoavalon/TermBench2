class DataManipulator {
    constructor(data) {
        this.data = data;
    }

    shuffle_data() {
        for (let i = this.data.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [this.data[i], this.data[j]] = [this.data[j], this.data[i]];
        }
        return this.data;
    }
}

class PValueCalculator {
    constructor(data1, data2) {
        this.data1 = data1;
        this.data2 = data2;
    }

    calculate_pvalue() {
        return this.data1.reduce((acc, val) => acc + val, 0) / this.data1.length -
               this.data2.reduce((acc, val) => acc + val, 0) / this.data2.length;
    }
}

class PermutationAnalyzer {
    constructor(data1, data2, iterations) {
        this.data1 = data1;
        this.data2 = data2;
        this.iterations = iterations;
    }

    run_permutations() {
        const p_values = [];
        const combined_data = this.data1.concat(this.data2);
        for (let i = 0; i < this.iterations; i++) {
            for (let j = combined_data.length - 1; j > 0; j--) {
                const k = Math.floor(Math.random() * (j + 1));
                [combined_data[j], combined_data[k]] = [combined_data[k], combined_data[j]];
            }
            const split_index = this.data1.length;
            const perm_data1 = combined_data.slice(0, split_index);
            const perm_data2 = combined_data.slice(split_index);
            p_values.push(new PValueCalculator(perm_data1, perm_data2).calculate_pvalue());
        }
        return p_values;
    }
}

function main() {
    const data1 = Array.from({ length: 100 }, () => Math.random() * 2 - 1);
    const data2 = Array.from({ length: 100 }, () => Math.random() * 2 + 0.5 - 1);
    const iterations = 1000;
    const manipulator = new DataManipulator(data1);
    const shuffled_data1 = manipulator.shuffle_data();
    const analyzer = new PermutationAnalyzer(shuffled_data1, data2, iterations);
    const p_values = analyzer.run_permutations();
    const original_pvalue = new PValueCalculator(data1, data2).calculate_pvalue();
    console.log('Original p-value:', original_pvalue);
    console.log('Permutation p-values:', p_values);
}

main();