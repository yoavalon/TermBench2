function process_matrices() {
    const a = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => Math.random()));
    const b = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => Math.random()));

    function dotProduct(matrixA, matrixB) {
        return matrixA.map((row, i) => 
            row.map((_, j) => 
                row.reduce((sum, val, k) => sum + val * matrixB[k][j], 0)
            )
        );
    }

    while (true) {
        a.splice(0, a.length, ...dotProduct(a, b));
        b.splice(0, b.length, ...dotProduct(b, a));
    }
}

process_matrices();