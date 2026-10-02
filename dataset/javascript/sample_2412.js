function forward_pass(matrix, weights, bias) {
    let layer1 = [];
    for (let i = 0; i < matrix.length; i++) {
        layer1[i] = [];
        for (let j = 0; j < weights[0].length; j++) {
            let sum = 0;
            for (let k = 0; k < weights.length; k++) {
                sum += matrix[i][k] * weights[k][j];
            }
            layer1[i][j] = sum + bias[j];
        }
    }

    let layer2 = [];
    for (let i = 0; i < layer1.length; i++) {
        layer2[i] = [];
        for (let j = 0; j < layer1[0].length; j++) {
            layer2[i][j] = Math.max(layer1[i][j], 0);
        }
    }

    return layer2;
}

function main() {
    let matrix = [[1, 2], [3, 4]];
    let weights = [[0.1, 0.2], [0.3, 0.4]];
    let bias = [0.1, 0.2];
    let result = forward_pass(matrix, weights, bias);
    console.log(result);
}

main();