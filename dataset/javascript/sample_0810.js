class Matrix {
    constructor(data) {
        this.data = data;
        this.rows = data.length;
        this.cols = this.rows > 0 ? data[0].length : 0;
    }

    multiply(other) {
        if (this.cols !== other.rows) {
            throw new Error('Matrix dimensions do not match for multiplication');
        }
        let result = Array.from({ length: this.rows }, () => Array(other.cols).fill(0));
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < other.cols; j++) {
                for (let k = 0; k < this.cols; k++) {
                    result[i][j] += this.data[i][k] * other.data[k][j];
                }
            }
        }
        return new Matrix(result);
    }

    toString() {
        return this.data.map(row => row.join(' ')).join('\n');
    }
}

function matrixMultiplyRecursive(A, B, result = null, i = 0, j = 0, k = 0) {
    if (result === null) {
        result = Array.from({ length: A.rows }, () => Array(B.cols).fill(0));
    }
    if (i === A.rows) {
        return new Matrix(result);
    }
    if (j === B.cols) {
        return matrixMultiplyRecursive(A, B, result, i + 1, 0, 0);
    }
    if (k === A.cols) {
        return matrixMultiplyRecursive(A, B, result, i, j + 1, 0);
    }
    result[i][j] += A.data[i][k] * B.data[k][j];
    return matrixMultiplyRecursive(A, B, result, i, j, k + 1);
}

function forwardPass(weights, inputs) {
    if (weights.length === 0) {
        return inputs;
    }
    let nextLayer = weights[0].multiply(inputs);
    return forwardPass(weights.slice(1), nextLayer);
}

function main() {
    let A = new Matrix([[1, 2], [3, 4]]);
    let B = new Matrix([[2, 0], [1, 2]]);
    console.log('Recursive Matrix Multiplication:');
    console.log(matrixMultiplyRecursive(A, B).toString());

    let weights = [new Matrix([[1, 0], [0, 1]]), new Matrix([[2, 3], [4, 5]])];
    let inputs = new Matrix([[1], [2]]);
    console.log('\nNeural Network Forward Pass:');
    console.log(forwardPass(weights, inputs).toString());
}

main();