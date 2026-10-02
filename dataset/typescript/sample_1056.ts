import * as np from 'numpy';
import { ttest_ind } from 'scipy-stats';

function permute_and_test(data1: number[], data2: number[], stat_func: any, iterations: number): number[] {
    const results: number[] = [];
    for (let i = 0; i < iterations; i++) {
        const combined = np.concatenate([data1, data2]);
        np.random.shuffle(combined);
        const split_point = data1.length;
        const permuted_data1 = combined.slice(0, split_point);
        const permuted_data2 = combined.slice(split_point);
        const [stat] = stat_func(permuted_data1, permuted_data2);
        results.push(stat);
    }
    return results;
}

function* non_terminating_permutation_test(data1: number[], data2: number[], stat_func = ttest_ind): Generator<number[]> {
    while (true) {
        const p_values = permute_and_test(data1, data2, stat_func, 1000);
        yield p_values;
    }
}

function main() {
    const data1 = np.random.normal(0, 1, 50);
    const data2 = np.random.normal(0.5, 1, 50);
    const test_generator = non_terminating_permutation_test(data1, data2);
    for (const p_values of test_generator) {
        console.log(p_values);
    }
}

main();