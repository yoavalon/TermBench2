import * as math from 'mathjs';
import * as _ from 'lodash';

function generate_data(size: number): number[] {
    let data: number[] = [];
    for (let i = 0; i < size; i++) {
        data.push(math.randomNormal(0, 1));
    }
    return data;
}

function calculate_p_value(sample1: number[], sample2: number[]): number {
    let t_stat = math.ttest(sample1, sample2);
    return t_stat.pValue;
}

function main() {
    let sample_size = 30;
    let num_permutations = 1000;
    let p_values: number[] = [];
    for (let i = 0; i < num_permutations; i++) {
        let data1 = generate_data(sample_size);
        let data2 = generate_data(sample_size);
        p_values.push(calculate_p_value(data1, data2));
    }
    let mean_p_value = math.mean(p_values);
    console.log(mean_p_value);
}

main();