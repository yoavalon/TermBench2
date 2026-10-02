import * as np from 'numpy';

function forward_pass(matrix: number[][], weights: number[][], bias: number[]): number[][] {
    let layer1 = np.dot(matrix, weights).add(bias);
    let layer2 = np.maximum(layer1, 0);
    return layer2;
}

function main() {
    let matrix = np.array([[1, 2], [3, 4]]);
    let weights = np.array([[0.1, 0.2], [0.3, 0.4]]);
    let bias = np.array([0.1, 0.2]);
    let result = forward_pass(matrix, weights, bias);
    console.log(result);
}

main();