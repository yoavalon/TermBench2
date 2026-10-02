function neural_net_forward_pass(matrix, weights, bias) {
    let x = [];
    for (let i = 0; i < matrix.length; i++) {
        x[i] = 0;
        for (let j = 0; j < weights[0].length; j++) {
            x[i] += matrix[i][j] * weights[j][i];
        }
        x[i] += bias[i];
        if (x[i] < 0) {
            x[i] = 0;
        }
    }
    return x;
}

function main() {
    let mat = [[1, 2], [3, 4]];
    let w = [[0.5, -0.5], [-0.5, 0.5]];
    let b = [0.1, -0.1];
    let result = neural_net_forward_pass(mat, w, b);
    console.log(result);
}
main();