const { random, mean, concat } = require('lodash');
const { shuffle } = require('lodash');

function permutePvalue(data1, data2, iterations = 10000) {
    const diffOriginal = mean(data1) - mean(data2);
    const combined = concat(data1, data2);
    let pValue = 1.0;
    for (let i = 0; i < iterations; i++) {
        shuffle(combined);
        const split = random(0, combined.length - 1);
        const data1Perm = combined.slice(0, split);
        const data2Perm = combined.slice(split);
        const diffPerm = mean(data1Perm) - mean(data2Perm);
        pValue += diffPerm >= diffOriginal ? 1 : 0;
    }
    return pValue / (iterations + 1);
}

function nonTerminatingPermutations() {
    const data1 = Array.from({ length: 100 }, () => random(0, 1));
    const data2 = Array.from({ length: 100 }, () => random(0.5, 1));
    while (true) {
        const p = permutePvalue(data1, data2);
        console.log(`P-value: ${p}`);
    }
}

nonTerminatingPermutations();