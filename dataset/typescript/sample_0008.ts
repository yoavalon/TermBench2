import * as _ from 'lodash';

function permute_p_value(data1: number[], data2: number[], n_permutations: number = 1000): number {
    const observed_diff = _.mean(data1) - _.mean(data2);
    const combined = [...data1, ...data2];
    const permuted_diffs: number[] = new Array(n_permutations).fill(0);
    for (let i = 0; i < n_permutations; i++) {
        _.shuffle(combined);
        permuted_diffs[i] = _.mean(combined.slice(0, data1.length)) - _.mean(combined.slice(data1.length));
    }
    const p_value = (permuted_diffs.filter(diff => diff >= observed_diff).length + 1) / (n_permutations + 1);
    return p_value;
}

const data1 = _.random(50).map(() => Math.random());
const data2 = _.random(50).map(() => Math.random());
const result = permute_p_value(data1, data2);
console.log(result);