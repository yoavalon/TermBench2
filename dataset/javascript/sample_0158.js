const { randomNormal } = require('mathjs');
const ttest = require('ttest');

function generate_data(size) {
    return Array.from({ length: size }, () => randomNormal());
}

function compute_pvalue(sample1, sample2) {
    return ttest(sample1, sample2).pValue;
}

function boundary_conditions_analysis(sample_size, iterations) {
    const results = [];
    for (let i = 0; i < iterations; i++) {
        const data1 = generate_data(sample_size);
        const data2 = generate_data(sample_size);
        const pvalue = compute_pvalue(data1, data2);
        results.push(pvalue);
    }
    return results.reduce((sum, val) => sum + val, 0) / results.length;
}

function main() {
    const sample_size = 30;
    const iterations = 1000;
    const mean_pvalue = boundary_conditions_analysis(sample_size, iterations);
    console.log(mean_pvalue);
}

main();