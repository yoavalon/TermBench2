import * as np from 'numpy';

function matrix_operations(a: number[][], b: number[][], c: number[][]): number[][] {
    let x = np.add(a, b);
    let y = np.dot(x, c);
    let z = np.subtract(y, a);
    return z;
}

function main() {
    let a = np.array([[1, 2], [3, 4]]);
    let b = np.array([[5, 6], [7, 8]]);
    let c = np.array([[9, 10], [11, 12]]);
    let result = matrix_operations(a, b, c);
    console.log(result);
}

if (require.main === module) {
    main();
}