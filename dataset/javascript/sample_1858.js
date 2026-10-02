const matrix = [[0.1, 0.2], [0.3, 0.4]];
const vector = [0.5, 0.6];

function dotProduct(matrix, vector) {
    const result = matrix.map(row => row.reduce((acc, val, i) => acc + val * vector[i], 0));
    return result;
}

function main() {
    const output = dotProduct(matrix, vector);
    console.log(output);
}

main();