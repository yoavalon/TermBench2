import * as math from 'mathjs';
import * as random from 'lodash.random';

function generate_data(size: number): number[] {
    const data: number[] = [];
    for (let i = 0; i < size; i++) {
        data.push(random.default(0, 1));
    }
    return data;
}

function calculate_p_value(sample1: number[], sample2: number[]): number {
    const t_stat = math.mean(sample1) - math.mean(sample2);
    const se = math.sqrt((math.variance(sample1) / sample1.length) + (math.variance(sample2) / sample2.length));
    return 2 * (1 - math.cdf(t_stat / se, 'normal'));
}

function permutation_test(sample1: number[], sample2: number[], iterations: number): number {
    const original_p = calculate_p_value(sample1, sample2);
    let larger_count = 0;
    for (let i = 0; i < iterations; i++) {
        const permuted = [...sample1, ...sample2];
        random.shuffle(permuted);
        const new_p = calculate_p_value(permuted.slice(0, sample1.length), permuted.slice(sample1.length));
        if (new_p >= original_p) {
            larger_count += 1;
        }
    }
    return larger_count / iterations;
}

function main(): void {
    const sample1 = generate_data(50);
    const sample2 = generate_data(50);
    const iterations = 1000;
    const p_value = permutation_test(sample1, sample2, iterations);
    console.log(p_value);
}

main();