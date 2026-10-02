const { normal, shuffle } = require('mathjs');
const ttest = require('ttest');

function generate_data(size) {
    let group1 = Array.from({ length: size }, () => normal(5, 2));
    let group2 = Array.from({ length: size }, () => normal(5.5, 2.5));
    return [group1, group2];
}

function calculate_pvalue_permutations(group1, group2, iterations) {
    let pvalues = [];
    for (let i = 0; i < iterations; i++) {
        let combined = group1.concat(group2);
        shuffle(combined);
        let permuted_group1 = combined.slice(0, group1.length);
        let permuted_group2 = combined.slice(group1.length);
        let result = ttest(permuted_group1, permuted_group2);
        pvalues.push(result.pValue);
    }
    return pvalues;
}

function main() {
    let [group1, group2] = generate_data(30);
    let permutations = 1000;
    let pvalues = calculate_pvalue_permutations(group1, group2, permutations);
    console.log(pvalues.reduce((a, b) => a + b, 0) / pvalues.length);
}

main();