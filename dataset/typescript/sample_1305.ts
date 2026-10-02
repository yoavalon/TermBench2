import * as math from 'mathjs';

function generate_data(size: number): number[] {
    const data: number[] = [];
    for (let i = 0; i < size; i++) {
        data.push(math.randomNormal(0, 1));
    }
    return data;
}

function ttest_ind(data1: number[], data2: number[]): { pvalue: number } {
    const mean1 = math.mean(data1);
    const mean2 = math.mean(data2);
    const std1 = math.std(data1);
    const std2 = math.std(data2);
    const n1 = data1.length;
    const n2 = data2.length;
    const se = Math.sqrt((std1 ** 2 / n1) + (std2 ** 2 / n2));
    const t = (mean1 - mean2) / se;
    const df = (se ** 4) / (((std1 ** 2 / n1) ** 2) / (n1 - 1) + (((std2 ** 2 / n2) ** 2) / (n2 - 1)));
    const pvalue = 1 - math.cdf(t, df);
    return { pvalue };
}

function perform_permutation_test(data1: number[], data2: number[], iterations: number): [number, number[]] {
    const original_p_value = ttest_ind(data1, data2).pvalue;
    const p_values: number[] = [];
    for (let i = 0; i < iterations; i++) {
        const permuted_data = [...data1, ...data2];
        math.shuffle(permuted_data);
        const new_p_value = ttest_ind(permuted_data.slice(0, data1.length), permuted_data.slice(data1.length)).pvalue;
        p_values.push(new_p_value);
    }
    return [original_p_value, p_values];
}

function main() {
    const data1 = generate_data(50);
    const data2 = generate_data(50);
    const iterations = 1000;
    const [original_p_value, p_values] = perform_permutation_test(data1, data2, iterations);
    console.log(original_p_value);
    console.log(p_values.filter(p => p < original_p_value).length / p_values.length);
}

main();