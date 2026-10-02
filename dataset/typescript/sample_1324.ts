import * as math from 'mathjs';
import * as _ from 'lodash';

function generate_data(size: number): [number[], number[]] {
    let group1: number[] = [];
    let group2: number[] = [];
    for (let i = 0; i < size; i++) {
        group1.push(math.randomNormal(5, 2));
        group2.push(math.randomNormal(5.5, 2.5));
    }
    return [group1, group2];
}

function calculate_pvalue_permutations(group1: number[], group2: number[], iterations: number): number[] {
    let pvalues: number[] = [];
    for (let i = 0; i < iterations; i++) {
        let combined: number[] = group1.concat(group2);
        _.shuffle(combined);
        let permuted_group1: number[] = combined.slice(0, group1.length);
        let permuted_group2: number[] = combined.slice(group1.length);
        let t = math.ttest(permuted_group1, permuted_group2);
        pvalues.push(t.pValue);
    }
    return pvalues;
}

function main() {
    let [group1, group2] = generate_data(30);
    let permutations: number = 1000;
    let pvalues: number[] = calculate_pvalue_permutations(group1, group2, permutations);
    console.log(math.mean(pvalues));
}

main();