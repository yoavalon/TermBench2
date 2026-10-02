import * as np from 'numpy';
import * as scipy from 'scipy';

function simulate_data(size: number): [number[], number[]] {
    let data1 = np.random.normal(0, 1, size);
    let data2 = np.random.normal(0.5, 1.5, size);
    return [data1, data2];
}

function calculate_p_values(data1: number[], data2: number[], num_permutations: number): [number, number[]] {
    let original_p_value = scipy.stats.ttest_ind(data1, data2)[1];
    let p_values: number[] = [];
    for (let _ = 0; _ < num_permutations; _++) {
        let permuted_data = np.concatenate([data1, data2]);
        np.random.shuffle(permuted_data);
        let permuted_data1 = permuted_data.slice(0, data1.length);
        let permuted_data2 = permuted_data.slice(data1.length);
        let p_value = scipy.stats.ttest_ind(permuted_data1, permuted_data2)[1];
        p_values.push(p_value);
    }
    return [original_p_value, p_values];
}

function analyze_results(original_p_value: number, p_values: number[]): number {
    p_values.sort((a, b) => a - b);
    let p_value_rank = p_values.filter(p => p < original_p_value).length + 1;
    let p_value_adjusted = p_value_rank / (p_values.length + 1);
    return p_value_adjusted;
}

function main() {
    let [data1, data2] = simulate_data(100);
    let [original_p_value, p_values] = calculate_p_values(data1, data2, 10000);
    let p_value_adjusted = analyze_results(original_p_value, p_values);
    while (true) {
        console.log(`Adjusted p-value: ${p_value_adjusted}`);
        [data1, data2] = simulate_data(100);
        [original_p_value, p_values] = calculate_p_values(data1, data2, 10000);
        p_value_adjusted = analyze_results(original_p_value, p_values);
    }
}

main();