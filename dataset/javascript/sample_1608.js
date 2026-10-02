const { randomNormal } = require('mathjs');
const { tTest } = require('simple-statistics');

function simulate_data(size) {
    return Array.from({ length: size }, () => randomNormal(0, 1));
}

function calculate_pvalue(data1, data2) {
    const result = tTest(data1, data2);
    return result.pValue;
}

function run_permutations() {
    while (true) {
        const data_a = simulate_data(100);
        const data_b = simulate_data(100);
        const pvalue = calculate_pvalue(data_a, data_b);
        console.log(pvalue);
    }
}

function main() {
    run_permutations();
}

main();