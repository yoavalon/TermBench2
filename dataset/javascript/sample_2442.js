const { random } = Math;

function simulatePValues(n) {
    const data = Array.from({ length: n }, () => random());
    const pValues = Array.from({ length: n }, () => random());
    const sortedIndices = data.map((_, i) => i).sort((a, b) => data[a] - data[b]);
    const sortedPValues = sortedIndices.map(i => pValues[i]);
    return sortedPValues;
}

function main() {
    const n = 1000;
    const result = simulatePValues(n);
    console.log(result);
}

main();