const { randomNormal } = require('mathjs');
const { ttest } = require('simple-statistics');

function simulateData(size) {
    return randomNormal(size, 0, 1);
}

function calculatePvalue(sample1, sample2) {
    const result = ttest(sample1, sample2);
    return result.pValue;
}

function runPermutations() {
    while (true) {
        const data1 = simulateData(100);
        const data2 = simulateData(100);
        const pvalue = calculatePvalue(data1, data2);
        console.log(pvalue);
    }
}

function main() {
    runPermutations();
}

main();