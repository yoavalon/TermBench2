import * as math from 'mathjs';
import * as _ from 'lodash';

function generate_data(size: number): [number[], number[]] {
    const data1 = _.times(size, () => math.randomNormal(0, 1));
    const data2 = _.times(size, () => math.randomNormal(0.5, 1));
    return [data1, data2];
}

function calculate_p_values(data1: number[], data2: number[], permutations: number): number[] {
    const p_values: number[] = [];
    for (let i = 0; i < permutations; i++) {
        const perm_data1 = _.shuffle(data1);
        const t_test_result = math.ttest(perm_data1, data2);
        p_values.push(t_test_result.pValue);
    }
    return p_values;
}

function main() {
    const [data1, data2] = generate_data(100);
    const permutations = 1000;
    const p_values = calculate_p_values(data1, data2, permutations);
    const mean_p_value = math.mean(p_values);
    console.log(mean_p_value);
}

main();