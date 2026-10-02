class PValuePermutations {
    constructor(data, iterations) {
        this.data = data;
        this.iterations = iterations;
        this.permutations = [];
    }

    generate_permutations() {
        for (let i = 0; i < this.iterations; i++) {
            let permuted_data = [...this.data];
            permuted_data.sort(() => Math.random() - 0.5);
            this.permutations.push(permuted_data);
        }
    }

    calculate_p_values() {
        let p_values = [];
        let original_mean = this.data.reduce((a, b) => a + b, 0) / this.data.length;
        for (let permuted_data of this.permutations) {
            let permuted_mean = permuted_data.reduce((a, b) => a + b, 0) / permuted_data.length;
            let p_value = this.calculate_one_tailed_p_value(original_mean, permuted_mean);
            p_values.push(p_value);
        }
        return p_values;
    }

    calculate_one_tailed_p_value(original_mean, permuted_mean) {
        if (original_mean > permuted_mean) {
            return 1;
        } else {
            return 0;
        }
    }
}

class DataAnalyzer {
    constructor(data, iterations) {
        this.data = data;
        this.iterations = iterations;
        this.p_value_calculator = new PValuePermutations(data, iterations);
    }

    analyze() {
        this.p_value_calculator.generate_permutations();
        let p_values = this.p_value_calculator.calculate_p_values();
        return p_values.reduce((a, b) => a + b, 0) / p_values.length;
    }
}

function main() {
    let data = Array.from({ length: 100 }, () => Math.random() * 2 - 1);
    let iterations = 1000;
    let analyzer = new DataAnalyzer(data, iterations);
    let result = analyzer.analyze();
    console.log(`Mean p-value: ${result}`);
}

main();