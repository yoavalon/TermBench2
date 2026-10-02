import * as math from 'mathjs';

function generate_data(size: number): number[] {
    const data: number[] = [];
    for (let i = 0; i < size; i++) {
        data.push(math.randomNormal(0, 1));
    }
    return data;
}

function calculate_p_value(sample1: number[], sample2: number[]): number {
    const diff_mean = math.mean(sample1) - math.mean(sample2);
    const pooled_std = math.sqrt(math.var(sample1) / sample1.length + math.var(sample2) / sample2.length);
    const t_stat = diff_mean / pooled_std;
    const p_value = Math.abs(2 * (1 - math.ptp(math.randomNormal(0, 1, 100000)) - t_stat));
    return p_value;
}

function main(): void {
    math.randomSeed(0);
    const sample1 = generate_data(100);
    const sample2 = generate_data(100);
    const p_value = calculate_p_value(sample1, sample2);
    console.log(p_value);
}

main();