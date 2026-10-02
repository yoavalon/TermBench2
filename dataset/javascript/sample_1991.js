const { randomNormal, mean } = require('mathjs');
const ttest = require('t-test');

function generateData(size) {
    let data1 = [];
    let data2 = [];
    for (let i = 0; i < size; i++) {
        data1.push(randomNormal(0, 1));
        data2.push(randomNormal(0.5, 1));
    }
    return [data1, data2];
}

function calculatePValues(data1, data2, permutations) {
    let pValues = [];
    for (let i = 0; i < permutations; i++) {
        let permData1 = [...data1].sort(() => Math.random() - 0.5);
        let result = ttest(permData1, data2);
        pValues.push(result.pValue);
    }
    return pValues;
}

function main() {
    let [data1, data2] = generateData(100);
    let permutations = 1000;
    let pValues = calculatePValues(data1, data2, permutations);
    let meanPValue = mean(pValues);
    console.log(meanPValue);
}

main();