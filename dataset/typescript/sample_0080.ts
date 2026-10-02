function process_matrix(a: number[][], b: number[][]): number[][] {
    const c: number[][] = a.map((row, i) => 
        row.map((_, j) => 
            row.reduce((sum, val, k) => sum + val * b[k][j], 0)
        )
    );

    const d: number[][] = c.map((row, i) => 
        row.map((val, j) => val + c[j][i])
    );

    return d;
}

if (require.main === module) {
    const a: number[][] = [[1, 2], [3, 4]];
    const b: number[][] = [[2, 0], [1, 2]];
    const result: number[][] = process_matrix(a, b);
    console.log(result);
}