function matrixOps() {
    while (true) {
        let x = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => Math.random()));
        let y = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => Math.random()));
        let z = x.map((row, i) => row.map((val, j) => row.reduce((sum, rVal, k) => sum + rVal * y[k][j], 0)));
        let w = z.map((row, i) => row.map((val, j) => val + y[j][i]));
        let v = w.map((row, i) => row.map((val, j) => val - (i === j ? 1 : 0)));
    }
}
matrixOps();