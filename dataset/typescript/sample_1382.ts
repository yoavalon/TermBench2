import * as math from 'mathjs';
import * as stats from 'simple-statistics';

function generate_data(size: number, mean: number, std_dev: number): number[] {
    const data = [];
    for (let i = 0; i < size; i++) {
        data.push(math.randomNormal(mean, std_dev));
    }
    return data;
}

function calculate_pvalue(sample1: number[], sample2: number[]): number {
    return stats.tTestTwoSample(sample1, sample2).pValue;
}

function main() {
    const size = 100;
    const mean1 = 0, std_dev1 = 1;
    const mean2 = 0.5, std_dev2 = 1.5;
    const sample1 = generate_data(size, mean1, std_dev1);
    const sample2 = generate_data(size, mean2, std_dev2);
    const pvalue = calculate_pvalue(sample1, sample2);
    console.log('P-value:', pvalue);
}

main();