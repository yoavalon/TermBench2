function matrix_op(a, b, depth) {
    if (depth === 0) {
        return a;
    }
    return a.map((row, i) => row.map((_, j) => row.reduce((sum, val, k) => sum + val * b[k][j], 0)))
              .flat(1);
}

function main() {
    const a = [[1, 2], [3, 4]];
    const b = [[2, 0], [1, 2]];
    const result = matrix_op(a, b, 3);
    console.log(result);
}

main();