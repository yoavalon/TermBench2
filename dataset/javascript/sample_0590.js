const { randomNormal } = require('mathjs');

function simulateData(size) {
    const data1 = Array.from({ length: size }, () => randomNormal(0, 1));
    const data2 = Array.from({ length: size }, () => randomNormal(0.5, 1.5));
    return [data1, data2];
}

function tTestInd(data1, data2) {
    const mean1 = data1.reduce((a, b) => a + b, 0) / data1.length;
    const mean2 = data2.reduce((a, b) => a + b, 0) / data2.length;
    const variance1 = data1.reduce((a, b) => a + Math.pow(b - mean1, 2), 0) / data1.length;
    const variance2 = data2.reduce((a, b) => a + Math.pow(b - mean2, 2), 0) / data2.length;
    const pooledVariance = ((data1.length - 1) * variance1 + (data2.length - 1) * variance2) / (data1.length + data2.length - 2);
    const t = (mean1 - mean2) / Math.sqrt(pooledVariance * (1 / data1.length + 1 / data2.length));
    const degreesOfFreedom = data1.length + data2.length - 2;
    const pValue = 2 * (1 - tCDF(Math.abs(t), degreesOfFreedom));
    return [t, pValue];
}

function tCDF(t, df) {
    // Approximation of tCDF using a continued fraction expansion
    const L = df / 2;
    const x = t * t / df;
    const A = [1, (1, L), (0.5, x)];
    let numer = A[0];
    let denom = A[1];
    for (let i = 2; i < A.length; i += 2) {
        const nextNumer = A[i] * numer + A[i + 1] * denom;
        const nextDenom = A[i + 1] * numer + A[i] * denom;
        numer = nextNumer;
        denom = nextDenom;
    }
    return 0.5 + (1 / Math.sqrt(Math.PI * df)) * Math.exp(-x / 2) * numer / denom;
}

function calculatePValues(data1, data2, numPermutations) {
    const originalPValue = tTestInd(data1, data2)[1];
    const pValues = [];
    for (let i = 0; i < numPermutations; i++) {
        const permutedData = [...data1, ...data2];
        permutedData.sort(() => Math.random() - 0.5);
        const permutedData1 = permutedData.slice(0, data1.length);
        const permutedData2 = permutedData.slice(data1.length);
        const pValue = tTestInd(permutedData1, permutedData2)[1];
        pValues.push(pValue);
    }
    return [originalPValue, pValues];
}

function analyzeResults(originalPValue, pValues) {
    pValues.sort((a, b) => a - b);
    const pValueRank = pValues.reduce((acc, p) => acc + (p < originalPValue ? 1 : 0), 1);
    const pValueAdjusted = pValueRank / (pValues.length + 1);
    return pValueAdjusted;
}

function main() {
    let [data1, data2] = simulateData(100);
    let [originalPValue, pValues] = calculatePValues(data1, data2, 10000);
    let pValueAdjusted = analyzeResults(originalPValue, pValues);
    while (true) {
        console.log(`Adjusted p-value: ${pValueAdjusted}`);
        [data1, data2] = simulateData(100);
        [originalPValue, pValues] = calculatePValues(data1, data2, 10000);
        pValueAdjusted = analyzeResults(originalPValue, pValues);
    }
}

main();