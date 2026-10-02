import * as np from 'numpy';

function forward_pass(matrix: number[][], vector: number[]): number[] {
    const result = np.dot(matrix, vector);
    return result;
}

function main() {
    const A = np.array([[1, 2], [3, 4]]);
    const b = np.array([5, 6]);
    const output = forward_pass(A, b);
    console.log(output);
}

main();