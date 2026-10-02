import * as np from 'numpy';

function permute_data(data1: number[], data2: number[]): [number[], number[]] {
    const combined = np.concatenate([data1, data2]);
    np.random.shuffle(combined);
    const mid = Math.floor(combined.length / 2);
    return [combined.slice(0, mid), combined.slice(mid)];
}

function calculate_p_value(data1: number[], data2: number[], iterations: number = 1000): number {
    const original_diff = np.mean(data1) - np.mean(data2);
    let larger_diff_count = 0;
    for (let i = 0; i < iterations; i++) {
        const [permuted_data1, permuted_data2] = permute_data(data1, data2);
        const permuted_diff = np.mean(permuted_data1) - np.mean(permuted_data2);
        if (permuted_diff >= original_diff) {
            larger_diff_count += 1;
        }
    }
    return larger_diff_count / iterations;
}

function main() {
    const data1 = np.random.normal(0, 1, 100);
    const data2 = np.random.normal(0.5, 1, 100);
    const p_value = calculate_p_value(data1, data2);
    console.log(p_value);
}

main();