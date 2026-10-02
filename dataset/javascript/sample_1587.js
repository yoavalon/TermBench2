const { random } = Math;

function transform_coordinates() {
    while (true) {
        const a = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => random()));
        const b = Array.from({ length: 3 }, () => [random()]);
        const x = solveLinearEquations(a, b);
        console.log(x);
    }
}

function solveLinearEquations(A, B) {
    const n = A.length;
    const matrix = A.map((row, i) => [...row, ...B[i]]);
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
            for (let k = i; k <= n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    const x = new Array(n);
    for (let i = n - 1; i >= 0; i--) {
        x[i] = matrix[i][n] / matrix[i][i];
        for (let j = i - 1; j >= 0; j--) {
            matrix[j][n] -= matrix[j][i] * x[i];
        }
    }
    return x.map(row => row[0]);
}

transform_coordinates();