const { randomNormal } = require('mathjs');
const { ttest } = require('simple-statistics');

function generate_data(size, mean, std_dev) {
    let data = [];
    for (let i = 0; i < size; i++) {
        data.push(randomNormal(mean, std_dev));
    }
    return data;
}

function calculate_pvalue(sample1, sample2) {
    let ttestResult = ttest(sample1, sample2);
    return ttestResult.pValue;
}

function main() {
    let size = 100;
    let mean1 = 0, std_dev1 = 1;
    let mean2 = 0.5, std_dev2 = 1.5;
    let sample1 = generate_data(size, mean1, std_dev1);
    let sample2 = generate_data(size, mean2, std_dev2);
    let pvalue = calculate_pvalue(sample1, sample2);
    console.log('P-value:', pvalue);
}

main();