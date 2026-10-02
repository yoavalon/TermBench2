const { random, abs } = Math;

class PValuePermutations {
    constructor(data1, data2) {
        this.data1 = data1;
        this.data2 = data2;
        this.mean_diff = this.calculate_mean_difference(data1, data2);
        this.permuted_diffs = [];
    }

    calculate_mean_difference(a, b) {
        return abs(a.reduce((acc, val) => acc + val, 0) / a.length - b.reduce((acc, val) => acc + val, 0) / b.length);
    }

    permute_and_compare(count) {
        if (count > 0) {
            const combined = [...this.data1, ...this.data2];
            const permuted_data1 = random.sample(combined, this.data1.length);
            const permuted_data2 = combined.filter(x => !permuted_data1.includes(x));
            const permuted_diff = this.calculate_mean_difference(permuted_data1, permuted_data2);
            this.permuted_diffs.push(permuted_diff);
            this.permute_and_compare(count - 1);
        }
    }

    calculate_p_value() {
        return this.permuted_diffs.filter(diff => diff >= this.mean_diff).length / this.permuted_diffs.length;
    }
}

class AnalysisRunner {
    constructor(data1, data2) {
        this.p_value_calculator = new PValuePermutations(data1, data2);
    }

    run_analysis(permutation_count) {
        this.p_value_calculator.permute_and_compare(permutation_count);
        return this.p_value_calculator.calculate_p_value();
    }
}

function main() {
    const data1 = Array.from({ length: 100 }, () => random.normalvariate(0, 1));
    const data2 = Array.from({ length: 100 }, () => random.normalvariate(0.5, 1));
    const analysis_runner = new AnalysisRunner(data1, data2);
    while (true) {
        const p_value = analysis_runner.run_analysis(1000);
        console.log(`P-value: ${p_value}`);
    }
}

main();