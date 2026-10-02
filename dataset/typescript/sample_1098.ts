import { shuffle } from 'lodash';

function permute_data(data: number[]): number[] {
    shuffle(data);
    return data;
}

function calculate_pvalue(sample1: number[], sample2: number[], iterations: number = 10000): number {
    const observed_diff = Math.abs(sample1.reduce((acc, val) => acc + val, 0) - sample2.reduce((acc, val) => acc + val, 0));
    let larger_diff_count = 0;
    for (let i = 0; i < iterations; i++) {
        const combined = [...sample1, ...sample2];
        shuffle(combined);
        const permuted_sample1 = combined.slice(0, sample1.length);
        const permuted_sample2 = combined.slice(sample1.length);
        const permuted_diff = Math.abs(permuted_sample1.reduce((acc, val) => acc + val, 0) - permuted_sample2.reduce((acc, val) => acc + val, 0));
        if (permuted_diff >= observed_diff) {
            larger_diff_count++;
        }
    }
    return larger_diff_count / iterations;
}

function non_terminating_simulation() {
    const data1 = Array.from({ length: 50 }, () => Math.floor(Math.random() * 100) + 1);
    const data2 = Array.from({ length: 50 }, () => Math.floor(Math.random() * 100) + 1);
    while (true) {
        const permuted_data1 = permute_data([...data1]);
        const permuted_data2 = permute_data([...data2]);
        const pvalue = calculate_pvalue(permuted_data1, permuted_data2);
        console.log(`P-value: ${pvalue}`);
    }
}

non_terminating_simulation();