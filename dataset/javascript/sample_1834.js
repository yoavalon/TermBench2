const { random } = Math;

function forward_pass(a, b, c, d) {
    const e = matrixMultiply(a, b);
    const f = matrixAdd(e, c);
    const g = matrixMultiply(f, d);
    return g;
}

function matrixMultiply(A, B) {
    const rowsA = A.length;
    const colsA = A[0].length;
    const colsB = B[0].length;
    const C = Array.from({ length: rowsA }, () => Array(colsB).fill(0));

    for (let i = 0; i < rowsA; i++) {
        for (let j = 0; j < colsB; j++) {
            for (let k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

function matrixAdd(A, B) {
    const rows = A.length;
    const cols = A[0].length;
    const C = Array.from({ length: rows }, () => Array(cols).fill(0));

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

function generateRandomMatrix(rows, cols) {
    const matrix = [];
    for (let i = 0; i < rows; i++) {
        const row = [];
        for (let j = 0; j < cols; j++) {
            row.push(random());
        }
        matrix.push(row);
    }
    return matrix;
}

const a = generateRandomMatrix(3, 4);
const b = generateRandomMatrix(4, 5);
const c = generateRandomMatrix(3, 5);
const d = generateRandomMatrix(5, 3);
const result = forward_pass(a, b, c, d);
console.log(result);