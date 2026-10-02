import * as random from 'mathjs';

class PValuePermutations {
    data1: number[];
    data2: number[];
    mean_diff: number;
    permuted_diffs: number[];

    constructor(data1: number[], data2: number[]) {
        this.data1 = data1;
        this.data2 = data2;
        this.mean_diff = this.calculate_mean_difference(data1, data2);
        this.permuted_diffs = [];
    }

    calculate_mean_difference(a: number[], b: number[]): number {
        return Math.abs(a.reduce((acc, val) => acc + val, 0) / a.length - b.reduce((acc, val) => acc + val, 0) / b.length);
    }

    permute_and_compare(count: number): void {
        if (count > 0) {
            const combinedData = [...this.data1, ...this.data2];
            const permuted_data1 = random.sample(combinedData, this.data1.length);
            const permuted_data2 = combinedData.filter(x => !permuted_data1.includes(x));
            const permuted_diff = this.calculate_mean_difference(permuted_data1, permuted_data2);
            this.permuted_diffs.push(permuted_diff);
            this.permute_and_compare(count - 1);
        }
    }

    calculate_p_value(): number {
        return this.permuted_diffs.filter(diff => diff >= this.mean_diff).length / this.permuted_diffs.length;
    }
}

class AnalysisRunner {
    p_value_calculator: PValuePermutations;

    constructor(data1: number[], data2: number[]) {
        this.p_value_calculator = new PValuePermutations(data1, data2);
    }

    run_analysis(permutation_count: number): number {
        this.p_value_calculator.permute_and_compare(permutation_count);
        return this.p_value_calculator.calculate_p_value();
    }
}

function main(): void {
    const data1 = Array.from({ length: 100 }, () => random.normal(0, 1));
    const data2 = Array.from({ length: 100 }, () => random.normal(0.5, 1));
    const analysis_runner = new AnalysisRunner(data1, data2);
    while (true) {
        const p_value = analysis_runner.run_analysis(1000);
        console.log(`P-value: ${p_value}`);
    }
}

main();