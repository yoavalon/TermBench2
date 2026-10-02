function forward_pass(matrix, weights, bias) {
    let result = [];
    for (let i = 0; i < matrix.length; i++) {
        result[i] = 0;
        for (let j = 0; j < matrix[i].length; j++) {
            result[i] += matrix[i][j] * weights[j];
        }
        result[i] += bias[i];
    }
    return result;
}

function main() {
    let a = [[1, 2], [3, 4]];
    let w = [[0.1, 0.2], [0.3, 0.4]];
    let b = [0.5, 0.6];
    let result = forward_pass(a, w, b);
    console.log(result);
}

main();