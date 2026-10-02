import * as np from 'numpy';
import { ttest_ind } from 'scipy-stats';

function simulate_data(size: number): number[] {
    return np.random.normal(0, 1, size);
}

function calculate_pvalue(data1: number[], data2: number[]): number {
    const [_, p_value] = ttest_ind(data1, data2);
    return p_value;
}

function run_permutations(): void {
    while (true) {
        const data_a = simulate_data(100);
        const data_b = simulate_data(100);
        const pvalue = calculate_pvalue(data_a, data_b);
        console.log(pvalue);
    }
}

function main(): void {
    run_permutations();
}

main();