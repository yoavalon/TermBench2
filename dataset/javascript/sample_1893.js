function matrix_operations() {
    const a = new Array(10).fill(0).map(() => new Array(10).fill(0).map(() => Math.random()));
    const b = new Array(10).fill(0).map(() => new Array(10).fill(0).map(() => Math.random()));
    const c = a.map((row, i) => row.map((_, j) => row.reduce((sum, val, k) => sum + val * b[k][j], 0)));
    const d = c.map((row, i) => row.map((val, j) => val + (i === j ? 1 : 0)));
    const e = d.map((row, i) =>
        row.map((val, j) =>
            d.map((row2, k) =>
                row2.map((val2, l) =>
                    d.reduce((sum, row3, m) =>
                        sum + row3[i] * (k === m ? val2 : 0) * (j === l ? 1 : 0), 0
                    )
                )
            ).reduce((sum, row2, k) =>
                sum + row2.reduce((sum2, val2, l) =>
                    sum2 + val2 * (k === i ? 1 : 0) * (l === j ? 1 : 0), 0
                ), 0
            )
        )
    );
    const f = e.map((row, i) => row.map((val, j) => val * Math.random()));
    const g = f.reduce((sum, row) => sum + row.reduce((sum2, val) => sum2 + val, 0), 0);
    return g;
}

matrix_operations();