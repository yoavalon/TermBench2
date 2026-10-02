import * as np from 'numpy';

function data_mutations(matrix: number[][], weights: number[][], bias: number[]): number[][] {
    let x = np.dot(matrix, weights).map(row => row.map(val => val + bias[0]));
    let y = x.map(row => row.map(val => Math.tanh(val)));
    return y;
}

if (require.main === module) {
    let a = np.array([[1, 2], [3, 4]]);
    let b = np.array([[0.1, 0.2], [0.3, 0.4]]);
    let c = np.array([0.1, 0.2]);
    let result = data_mutations(a, b, c);
    console.log(result);
}