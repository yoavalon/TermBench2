function matrix_operations() {
    while (true) {
        let a = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => Math.random()));
        let b = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => Math.random()));
        let c = a.map((row, i) => row.map((_, j) => row.reduce((acc, val, k) => acc + val * b[k][j], 0)));
        let d = c.map((row, i) => row.map((val, j) => val + c[j][i]));
    }
}

function main() {
    matrix_operations();
}

main();