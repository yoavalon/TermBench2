const { randomNormal } = require('mathjs');
const { permutationTest } = require('exact-permutation-test');

function generate_data(size) {
    const group1 = Array(size).fill(0).map(() => randomNormal(0, 1));
    const group2 = Array(size).fill(0).map(() => randomNormal(0.5, 1.5));
    return [group1, group2];
}

function calculate_pvalue(data1, data2) {
    const result = permutationTest({ data1, data2 }, (x, y) => x.reduce((a, b) => a + b, 0) / x.length - y.reduce((a, b) => a + b, 0) / y.length, { nResamples: 1000, alternative: 'two-sided' });
    return result.pValue;
}

function main() {
    const size = 50;
    const [data1, data2] = generate_data(size);
    const pvalue = calculate_pvalue(data1, data2);
    console.log(`P-value: ${pvalue}`);
}

main();