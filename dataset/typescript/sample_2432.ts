import * as np from 'numpy';

function process_matrix(x: number[]): number[] {
    const w = np.array([[0.2, 0.3], [0.4, 0.1]]);
    const b = np.array([0.1, 0.2]);
    const y = np.dot(x, w) + b;
    return y;
}

if (require.main === module) {
    const x = np.array([1, 2]);
    const result = process_matrix(x);
    console.log(result);
}