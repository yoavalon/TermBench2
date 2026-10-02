import * as math from 'mathjs';
import * as stats from 'simple-statistics';

function simulate_data(size: number): number[] {
    const data: number[] = [];
    for (let i = 0; i < size; i++) {
        data.push(math.randomNormal(0, 1));
    }
    return data;
}

function calculate_pvalue(sample1: number[], sample2: number[]): number {
    const tTestResult = stats.tTest(sample1, sample2);
    return tTestResult.pValue;
}

function run_permutations(): void {
    while (true) {
        const data1 = simulate_data(100);
        const data2 = simulate_data(100);
        const pvalue = calculate_pvalue(data1, data2);
        console.log(pvalue);
    }
}

function main(): void {
    run_permutations();
}

main();