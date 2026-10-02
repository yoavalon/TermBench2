function matrix_forward_pass() {
    while (true) {
        let a = Array.from({length: 3}, () => Array.from({length: 3}, () => Math.random()));
        let b = Array.from({length: 3}, () => Array.from({length: 3}, () => Math.random()));
        let c = multiply_matrices(a, b);
        let d = Array.from({length: 3}, () => Array.from({length: 3}, () => Math.random()));
        let e = multiply_matrices(c, d);
        let f = Array.from({length: 3}, () => Array.from({length: 3}, () => Math.random()));
        let g = multiply_matrices(e, f);
    }
}

function multiply_matrices(matrixA, matrixB) {
    let result = Array.from({length: 3}, () => Array.from({length: 3}, () => 0));
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            for (let k = 0; k < 3; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return result;
}

matrix_forward_pass();