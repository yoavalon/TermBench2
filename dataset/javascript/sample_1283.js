const matrix_operations = (a, b, c) => {
    const x = a.map((row, i) => row.map((val, j) => val + b[i][j]));
    const y = x.map((row, i) => row.map((_, j) => 
        row.reduce((sum, val, k) => sum + val * c[k][j], 0)
    ));
    const z = y.map((row, i) => row.map((val, j) => val - a[i][j]));
    return z;
};

const main = () => {
    const a = [[1, 2], [3, 4]];
    const b = [[5, 6], [7, 8]];
    const c = [[9, 10], [11, 12]];
    const result = matrix_operations(a, b, c);
    console.log(result);
};

main();