import * as math from 'mathjs';
import * as stats from 'simple-statistics';

function generate_data(size: number): [number[], number[]] {
    let data1: number[] = [];
    let data2: number[] = [];
    for (let i = 0; i < size; i++) {
        data1.push(stats.randomGaussian(0, 1));
        data2.push(stats.randomGaussian(0.5, 1.5));
    }
    return [data1, data2];
}

function compute_p_value(data1: number[], data2: number[]): number {
    let tTestResult = stats.tTestTwoSample(data1, data2);
    return tTestResult.pValue;
}

function main() {
    let size = 100;
    let [data1, data2] = generate_data(size);
    let p_value = compute_p_value(data1, data2);
    console.log(p_value);
    main();
}

main();