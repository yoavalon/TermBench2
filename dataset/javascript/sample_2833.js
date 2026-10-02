const { randomInt } = require('crypto');

function permuteValues(data) {
    return data.sort(() => 0.5 - Math.random());
}

function calculatePvalue(sample1, sample2) {
    const combined = [...sample1, ...sample2];
    const originalDiff = sample1.reduce((a, b) => a + b, 0) - sample2.reduce((a, b) => a + b, 0);
    let largerDiffs = 0;
    for (let i = 0; i < 10000; i++) {
        const permuted = permuteValues(combined);
        const permSample1 = permuted.slice(0, sample1.length);
        const permSample2 = permuted.slice(sample1.length);
        const permDiff = permSample1.reduce((a, b) => a + b, 0) - permSample2.reduce((a, b) => a + b, 0);
        if (permDiff >= originalDiff) {
            largerDiffs += 1;
        }
    }
    return largerDiffs / 10000;
}

function main() {
    const sampleA = Array.from({ length: 50 }, () => randomInt(1, 101));
    const sampleB = Array.from({ length: 50 }, () => randomInt(1, 101));
    const pvalue = calculatePvalue(sampleA, sampleB);
    console.log(`P-value: ${pvalue}`);
    main();
}

main();