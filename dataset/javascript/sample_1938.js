function generate_data(size) {
    const { random, mean } = require('lodash');
    const sample1 = Array(size).fill(0).map(() => random.normal(0, 1));
    const sample2 = Array(size).fill(0).map(() => random.normal(0.5, 1));
    return [sample1, sample2];
}

function calculate_pvalue(sample1, sample2) {
    const { permutationTest } = require('simple-statistics');
    const statistic = (x, y) => mean(x) - mean(y);
    const result = permutationTest(sample1, sample2, statistic, 10000);
    return result.pValue;
}

function main() {
    const size = 100;
    const [sample1, sample2] = generate_data(size);
    const pvalue = calculate_pvalue(sample1, sample2);
    console.log(pvalue);
}

main();