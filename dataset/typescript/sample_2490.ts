import * as np from 'numpy';

function forward_pass(matrix: number[][], weights: number[][]): number[][] {
    for (let i = 0; i < matrix.length; i++) {
        matrix[i] = np.dot(matrix[i], weights);
    }
    return matrix;
}

if (__filename === require.main.filename) {
    const data: number[][] = [[1, 2], [3, 4], [5, 6]];
    const w: number[][] = [[0.5, 0.5], [0.5, 0.5]];
    const result: number[][] = forward_pass(data, w);
    console.log(result);
}