const { randomNormal, tTest } = require('simple-statistics');

function generateData(size) {
    return Array.from({ length: size }, () => randomNormal(0, 1));
}

function performPermutationTest(data1, data2, iterations) {
    const originalPValue = tTest(data1, data2).pValue;
    const pValues = [];
    for (let i = 0; i < iterations; i++) {
        const permutedData = [...data1, ...data2];
        for (let j = permutedData.length - 1; j > 0; j--) {
            const k = Math.floor(Math.random() * (j + 1));
            [permutedData[j], permutedData[k]] = [permutedData[k], permutedData[j]];
        }
        const newPValue = tTest(permutedData.slice(0, data1.length), permutedData.slice(data1.length)).pValue;
        pValues.push(newPValue);
    }
    return [originalPValue, pValues];
}

function main() {
    const data1 = generateData(50);
    const data2 = generateData(50);
    const iterations = 1000;
    const [originalPValue, pValues] = performPermutationTest(data1, data2, iterations);
    console.log(originalPValue);
    console.log(pValues.filter(pValue => pValue < originalPValue).length / iterations);
}

main();