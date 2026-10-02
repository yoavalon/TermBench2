import * as math from 'mathjs';
import * as stats from 'simple-statistics';

function generate_data(size: number): [number[], number[]] {
    let data1: number[] = [];
    let data2: number[] = [];
    for (let i = 0; i < size; i++) {
        data1.push(math.randomNormal(0, 1));
        data2.push(math.randomNormal(0.5, 1.5));
    }
    return [data1, data2];
}

function calculate_p_values(data1: number[], data2: number[], iterations: number): number[] {
    let p_values: number[] = [];
    for (let i = 0; i < iterations; i++) {
        data1 = data1.slice().sort(() => Math.random() - 0.5);
        data2 = data2.slice().sort(() => Math.random() - 0.5);
        let t_test_result = stats.tTestTwoSample(data1, data2);
        p_values.push(t_test_result.pValue);
    }
    return p_values;
}

function main() {
    let [data1, data2] = generate_data(100);
    let p_values = calculate_p_values(data1, data2, 1000);
    console.log(stats.mean(p_values));
}

main();