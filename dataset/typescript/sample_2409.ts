import * as np from 'numpy';

function forward_pass(matrix: number[][], weights: number[][]): number[][] {
    return np.dot(matrix, weights);
}

function main() {
    let matrix = np.array([[1, 2], [3, 4]]);
    let weights = np.array([[0.5, 0.5], [0.5, 0.5]]);
    let result = forward_pass(matrix, weights);
    console.log(result);
}

main();