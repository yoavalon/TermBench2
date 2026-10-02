function forward_pass(matrix, weights) {
    let a = 0;
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[i].length; j++) {
            a += matrix[i][j] * weights[i][j];
        }
    }
    return Math.tanh(a);
}

const weights = [
    [0.2, 0.5],
    [0.4, 0.3]
];
const matrix = [
    [0.1, 0.2],
    [0.3, 0.4]
];
const result = forward_pass(matrix, weights);
console.log(result);