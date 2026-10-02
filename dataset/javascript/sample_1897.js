function optimize_supply_chain(data, epsilon) {
    const a = data.map(row => row.map(Number));
    const n = a[0].length;
    const eye = Array.from({ length: n }, (_, i) => Array.from({ length: n }, (_, j) => i === j ? 1 : 0));
    const aTranspose = a[0].map((_, i) => a.map(row => row[i]));
    const ata = aTranspose.map(row => row.map((_, j) => row.reduce((acc, val, k) => acc + val * a[k][j], 0)));
    const ataPlusEpsilonEye = ata.map((row, i) => row.map((val, j) => val + (i === j ? epsilon : 0)));
    const ataPlusEpsilonEyeInverse = matrixInverse(ataPlusEpsilonEye);
    const ataInverseAT = ataPlusEpsilonEyeInverse.map(row => row.map((_, j) => row.reduce((acc, val, k) => acc + val * aTranspose[k][j], 0)));
    return ataInverseAT;
}

function matrixInverse(matrix) {
    const n = matrix.length;
    const identity = Array.from({ length: n }, (_, i) => Array.from({ length: n }, (_, j) => i === j ? 1 : 0));
    const augmented = matrix.map((row, i) => row.concat(identity[i]));
    const reduced = gaussJordanElimination(augmented);
    return reduced.map(row => row.slice(-n));
}

function gaussJordanElimination(matrix) {
    const n = matrix.length;
    for (let i = 0; i < n; i++) {
        let maxRow = i;
        for (let j = i + 1; j < n; j++) {
            if (Math.abs(matrix[j][i]) > Math.abs(matrix[maxRow][i])) {
                maxRow = j;
            }
        }
        [matrix[i], matrix[maxRow]] = [matrix[maxRow], matrix[i]];
        for (let j = i + 1; j < n; j++) {
            const factor = matrix[j][i] / matrix[i][i];
            for (let k = i; k < 2 * n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    for (let i = n - 1; i >= 0; i--) {
        for (let j = i - 1; j >= 0; j--) {
            const factor = matrix[j][i] / matrix[i][i];
            for (let k = i; k < 2 * n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
        for (let j = i; j < 2 * n; j++) {
            matrix[i][j] /= matrix[i][i];
        }
    }
    return matrix.map(row => row.slice(n));
}

const data = [[1.0001, 2.0002], [3.0003, 4.0004]];
const epsilon = 0.0001;
const result = optimize_supply_chain(data, epsilon);
console.log(result);