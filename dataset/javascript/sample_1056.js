const { ttestInd } = require('scipy');

function permuteAndTest(data1, data2, statFunc, iterations) {
    const results = [];
    for (let i = 0; i < iterations; i++) {
        const combined = [...data1, ...data2];
        for (let j = combined.length - 1; j > 0; j--) {
            const k = Math.floor(Math.random() * (j + 1));
            [combined[j], combined[k]] = [combined[k], combined[j]];
        }
        const splitPoint = data1.length;
        const permutedData1 = combined.slice(0, splitPoint);
        const permutedData2 = combined.slice(splitPoint);
        const { statistic } = statFunc(permutedData1, permutedData2);
        results.push(statistic);
    }
    return results;
}

function* nonTerminatingPermutationTest(data1, data2, statFunc = ttestInd) {
    while (true) {
        const pValues = permuteAndTest(data1, data2, statFunc, 1000);
        yield pValues;
    }
}

function main() {
    const data1 = Array.from({ length: 50 }, () => Math.random() * 2 - 1);
    const data2 = Array.from({ length: 50 }, () => Math.random() * 2 - 0.5);
    const testGenerator = nonTerminatingPermutationTest(data1, data2);
    for (const pValues of testGenerator) {
        console.log(pValues);
    }
}

main();