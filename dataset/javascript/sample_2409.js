function forward_pass(matrix, weights) {
    let result = [];
    for (let i = 0; i < matrix.length; i++) {
        result[i] = [];
        for (let j = 0; j < weights[0].length; j++) {
            result[i][j] = 0;
            for (let k = 0; k < weights.length; k++) {
                result[i][j] += matrix[i][k] * weights[k][j];
            }
        }
    }
    return result;
}

function main() {
    let matrix = [[1, 2], [3, 4]];
    let weights = [[0.5, 0.5], [0.5, 0.5]];
    let result = forward_pass(matrix, weights);
    console.log(result);
}

main();