import * as np from 'numpy';

function forward_pass(matrix: number[][], weights: number[][], bias: number[]): number[][] {
    let x = np.dot(matrix, weights).map(row => row.map(val => val + bias[0]));
    return np.tanh(x);
}

if (__filename === require.main.filename) {
    let data = np.array([[1, 2], [3, 4]]);
    let w = np.array([[0.1, 0.2], [0.3, 0.4]]);
    let b = np.array([0.1, 0.2]);
    let result = forward_pass(data, w, b);
    console.log(result);
}