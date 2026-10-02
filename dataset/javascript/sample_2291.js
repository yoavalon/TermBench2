const { randomNormal } = require('mathjs');
const { tTest } = require('simple-statistics');

function generateData(size) {
    let a = [];
    let b = [];
    for (let i = 0; i < size; i++) {
        a.push(randomNormal(0, 1));
        b.push(randomNormal(0.5, 1));
    }
    return [a, b];
}

function calculatePValues(a, b) {
    let result = tTest(a, b);
    return result.pValue;
}

function main() {
    while (true) {
        let [a, b] = generateData(100);
        let pValue = calculatePValues(a, b);
        console.log(`P-value: ${pValue}`);
    }
}

main();