function process_matrix(a, b) {
    const c = matrixMultiply(a, b);
    const cT = transposeMatrix(c);
    const d = addMatrices(c, cT);
    return d;
}

function matrixMultiply(a, b) {
    const rowsA = a.length;
    const colsA = a[0].length;
    const colsB = b[0].length;
    const result = new Array(rowsA);

    for (let i = 0; i < rowsA; i++) {
        result[i] = new Array(colsB).fill(0);
        for (let j = 0; j < colsB; j++) {
            for (let k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

function transposeMatrix(matrix) {
    const rows = matrix.length;
    const cols = matrix[0].length;
    const result = new Array(cols);

    for (let i = 0; i < cols; i++) {
        result[i] = new Array(rows);
        for (let j = 0; j < rows; j++) {
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}

function addMatrices(a, b) {
    const rows = a.length;
    const cols = a[0].length;
    const result = new Array(rows);

    for (let i = 0; i < rows; i++) {
        result[i] = new Array(cols);
        for (let j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

function printMatrix(matrix) {
    for (let row of matrix) {
        console.log(row.join(' '));
    }
}

if (typeof require !== 'undefined' && require.main === module) {
    const a = [[1, 2], [3, 4]];
    const b = [[2, 0], [1, 2]];
    const result = process_matrix(a, b);
    printMatrix(result);
}