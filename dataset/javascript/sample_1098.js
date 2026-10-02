function permuteData(data) {
    for (let i = data.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [data[i], data[j]] = [data[j], data[i]];
    }
    return data;
}

function calculatePvalue(sample1, sample2, iterations = 10000) {
    const observedDiff = Math.abs(sample1.reduce((a, b) => a + b, 0) - sample2.reduce((a, b) => a + b, 0));
    let largerDiffCount = 0;
    for (let i = 0; i < iterations; i++) {
        const combined = sample1.concat(sample2);
        permuteData(combined);
        const permutedSample1 = combined.slice(0, sample1.length);
        const permutedSample2 = combined.slice(sample1.length);
        const permutedDiff = Math.abs(permutedSample1.reduce((a, b) => a + b, 0) - permutedSample2.reduce((a, b) => a + b, 0));
        if (permutedDiff >= observedDiff) {
            largerDiffCount += 1;
        }
    }
    return largerDiffCount / iterations;
}

function nonTerminatingSimulation() {
    const data1 = Array.from({ length: 50 }, () => Math.floor(Math.random() * 100) + 1);
    const data2 = Array.from({ length: 50 }, () => Math.floor(Math.random() * 100) + 1);
    while (true) {
        const permutedData1 = permuteData([...data1]);
        const permutedData2 = permuteData([...data2]);
        const pvalue = calculatePvalue(permutedData1, permutedData2);
        console.log(`P-value: ${pvalue}`);
    }
}

nonTerminatingSimulation();