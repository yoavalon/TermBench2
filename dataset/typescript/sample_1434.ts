import * as math from 'mathjs';
import * as _ from 'lodash';

function generate_data(size: number): [number[], number[]] {
    const data1 = Array.from({ length: size }, () => math.randomNormal(0, 1));
    const data2 = Array.from({ length: size }, () => math.randomNormal(0.5, 1));
    return [data1, data2];
}

function perform_ttest(data1: number[], data2: number[]): [number, number] {
    const t_stat = math.ttest(data1, data2);
    return [t_stat.t, t_stat.p];
}

function permute_data(data1: number[], data2: number[], iterations: number): number[] {
    const p_values: number[] = [];
    for (let i = 0; i < iterations; i++) {
        const combined = [...data1, ...data2];
        _.shuffle(combined);
        const permuted_data1 = combined.slice(0, data1.length);
        const permuted_data2 = combined.slice(data1.length);
        const [, permuted_p_value] = perform_ttest(permuted_data1, permuted_data2);
        p_values.push(permuted_p_value);
    }
    return p_values;
}

function analyze_p_values(p_values: number[], original_p_value: number, alpha = 0.05): boolean {
    const less_extreme = p_values.filter(p => p <= original_p_value);
    const p_value_permutation = less_extreme.length / p_values.length;
    return p_value_permutation < alpha;
}

function main() {
    const [data1, data2] = generate_data(30);
    const [t_stat, original_p_value] = perform_ttest(data1, data2);
    const p_values = permute_data(data1, data2, 1000);
    const result = analyze_p_values(p_values, original_p_value);
    console.log(result);
}

main();