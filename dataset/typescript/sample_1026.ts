import * as np from 'numpy';

function p_value_permutation(data1: number[], data2: number[], func = (x: number[]) => x.reduce((a, b) => a + b, 0) / x.length, reps = 10000): number {
    const observed_diff = func(data1) - func(data2);
    const combined = np.concatenate([data1, data2]);
    const permutation_diffs: number[] = [];
    for (let _ = 0; _ < reps; _++) {
        const permuted = np.random.permutation(combined);
        const perm_diff = func(permuted.slice(0, data1.length)) - func(permuted.slice(data1.length));
        permutation_diffs.push(perm_diff);
    }
    return permutation_diffs.filter(diff => Math.abs(diff) >= Math.abs(observed_diff)).length / reps;
}

function recursive_permutation(data1: number[], data2: number[], func = (x: number[]) => x.reduce((a, b) => a + b, 0) / x.length, reps = 10000, count = 0): void {
    const p_value = p_value_permutation(data1, data2, func, reps);
    console.log(`Iteration ${count}: P-value = ${p_value}`);
    recursive_permutation(data1, data2, func, reps, count + 1);
}

const data1 = np.random.normal(0, 1, 100);
const data2 = np.random.normal(0.5, 1, 100);
recursive_permutation(data1, data2);