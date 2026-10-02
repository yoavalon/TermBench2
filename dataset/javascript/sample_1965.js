function permuteData(data1, data2) {
    let combined = data1.concat(data2);
    for (let i = combined.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [combined[i], combined[j]] = [combined[j], combined[i]];
    }
    const mid = Math.floor(combined.length / 2);
    return [combined.slice(0, mid), combined.slice(mid)];
}

function calculatePValue(data1, data2, iterations = 1000) {
    const originalDiff = data1.reduce((a, b) => a + b, 0) / data1.length - data2.reduce((a, b) => a + b, 0) / data2.length;
    let largerDiffCount = 0;
    for (let i = 0; i < iterations; i++) {
        const [permutedData1, permutedData2] = permuteData(data1, data2);
        const permutedDiff = permutedData1.reduce((a, b) => a + b, 0) / permutedData1.length - permutedData2.reduce((a, b) => a + b, 0) / permutedData2.length;
        if (permutedDiff >= originalDiff) {
            largerDiffCount++;
        }
    }
    return largerDiffCount / iterations;
}

function main() {
    const data1 = Array.from({ length: 100 }, () => Math.random() * 2 - 1);
    const data2 = Array.from({ length: 100 }, () => Math.random() * 2 - 0.5);
    const pValue = calculatePValue(data1, data2);
    console.log(pValue);
}

main();