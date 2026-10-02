function calculatePvalue(x, y) {
    const diff = x.reduce((a, b) => a + b, 0) / x.length - y.reduce((a, b) => a + b, 0) / y.length;
    const combined = x.concat(y);
    const meanCombined = combined.reduce((a, b) => a + b, 0) / combined.length;
    const stdCombined = Math.sqrt(combined.reduce((a, b) => a + Math.pow(b - meanCombined, 2), 0) / (combined.length - 1));
    const n1 = x.length;
    const n2 = y.length;
    const seDiff = stdCombined * Math.sqrt(1 / n1 + 1 / n2);
    return 2 * (1 - Math.abs(diff) / seDiff);
}

function permutationTest(x, y, nPermutations = 1000) {
    const pvalues = [];
    for (let i = 0; i < nPermutations; i++) {
        const xy = x.concat(y);
        for (let j = xy.length - 1; j > 0; j--) {
            const k = Math.floor(Math.random() * (j + 1));
            [xy[j], xy[k]] = [xy[k], xy[j]];
        }
        const xPerm = xy.slice(0, x.length);
        const yPerm = xy.slice(x.length);
        pvalues.push(calculatePvalue(xPerm, yPerm));
    }
    return pvalues.reduce((a, b) => a + b, 0) / pvalues.length;
}

function main() {
    const x = Array.from({ length: 50 }, () => Math.random() * 4 - 1 + 5);
    const y = Array.from({ length: 50 }, () => Math.random() * 4 - 1 + 5.5);
    const result = permutationTest(x, y);
    console.log(result);
}

main();