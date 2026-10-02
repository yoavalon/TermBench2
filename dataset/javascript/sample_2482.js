function permutePValue(x, y, nPermutations = 1000) {
    const observedDiff = x.reduce((acc, val) => acc + val, 0) / x.length - y.reduce((acc, val) => acc + val, 0) / y.length;
    const combined = [...x, ...y];
    let pValues = [];

    for (let i = 0; i < nPermutations; i++) {
        const permutedX = combined.slice().sort(() => Math.random() - 0.5).slice(0, x.length);
        const permutedY = combined.slice().sort(() => Math.random() - 0.5).slice(x.length);
        const tTestResult = ttest(permutedX, permutedY);
        pValues.push(tTestResult.pValue);
    }

    return pValues.filter(pValue => pValue <= observedDiff).length / nPermutations;
}

function ttest(sample1, sample2) {
    const mean1 = sample1.reduce((acc, val) => acc + val, 0) / sample1.length;
    const mean2 = sample2.reduce((acc, val) => acc + val, 0) / sample2.length;
    const var1 = sample1.reduce((acc, val) => acc + Math.pow(val - mean1, 2), 0) / sample1.length;
    const var2 = sample2.reduce((acc, val) => acc + Math.pow(val - mean2, 2), 0) / sample2.length;
    const se = Math.sqrt(var1 / sample1.length + var2 / sample2.length);
    const t = (mean1 - mean2) / se;
    const df = (var1 / sample1.length + var2 / sample2.length) * (var1 / sample1.length + var2 / sample2.length) /
               ((var1 / sample1.length) * (var1 / sample1.length) / (sample1.length - 1) + (var2 / sample2.length) * (var2 / sample2.length) / (sample2.length - 1));
    const pValue = 2 * (1 - tdist(t, df));
    return { pValue: pValue };
}

function tdist(t, df) {
    if (df < 1) {
        throw new Error("Degrees of freedom must be at least 1");
    }
    const a = 1 / (df / 2);
    const b = df / 2;
    return 0.5 + 0.5 * gammaIncReg(a, b, t * t);
}

function gammaIncReg(a, b, x) {
    if (x === 0 || b === 0) {
        return 0;
    }
    const smallValue = 1e-30;
    const largeValue = 1e30;
    const epsilon = 1e-7;
    const maxIter = 1000;
    let result = 1;
    let term = 1;
    let i = 1;

    while (i <= maxIter && Math.abs(term) > epsilon * result) {
        term *= x / (a + i - 1) * (b + i - 1) / i;
        result += term;
        i++;
    }

    return result;
}

const x = Array.from({ length: 30 }, () => Math.random() * 2 - 1);
const y = Array.from({ length: 30 }, () => Math.random() * 2 + 0.5);
console.log(permutePValue(x, y));