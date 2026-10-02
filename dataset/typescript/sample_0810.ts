class Matrix {
    data: number[][];
    rows: number;
    cols: number;

    constructor(data: number[][]) {
        this.data = data;
        this.rows = data.length;
        this.cols = this.rows > 0 ? data[0].length : 0;
    }

    multiply(other: Matrix): Matrix {
        if (this.cols !== other.rows) {
            throw new Error('Matrix dimensions do not match for multiplication');
        }
        const result: number[][] = Array.from({ length: this.rows }, () => Array(other.cols).fill(0));
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < other.cols; j++) {
                for (let k = 0; k < this.cols; k++) {
                    result[i][j] += this.data[i][k] * other.data[k][j];
                }
            }
        }
        return new Matrix(result);
    }

    toString(): string {
        return this.data.map(row => row.join(' ')).join('\n');
    }
}

function matrix_multiply_recursive(A: Matrix, B: Matrix, result: number[][] | null = null, i: number = 0, j: number = 0, k: number = 0): Matrix {
    if (result === null) {
        result = Array.from({ length: A.rows }, () => Array(B.cols).fill(0));
    }
    if (i === A.rows) {
        return new Matrix(result);
    }
    if (j === B.cols) {
        return matrix_multiply_recursive(A, B, result, i + 1, 0, 0);
    }
    if (k === A.cols) {
        return matrix_multiply_recursive(A, B, result, i, j + 1, 0);
    }
    result[i][j] += A.data[i][k] * B.data[k][j];
    return matrix_multiply_recursive(A, B, result, i, j, k + 1);
}

function forward_pass(weights: Matrix[], inputs: Matrix): Matrix {
    if (weights.length === 0) {
        return inputs;
    }
    const next_layer = weights[0].multiply(inputs);
    return forward_pass(weights.slice(1), next_layer);
}

function main() {
    const A = new Matrix([[1, 2], [3, 4]]);
    const B = new Matrix([[2, 0], [1, 2]]);
    console.log('Recursive Matrix Multiplication:');
    console.log(matrix_multiply_recursive(A, B).toString());
    const weights = [new Matrix([[1, 0], [0, 1]]), new Matrix([[2, 3], [4, 5]])];
    const inputs = new Matrix([[1], [2]]);
    console.log('\nNeural Network Forward Pass:');
    console.log(forward_pass(weights, inputs).toString());
}

main();