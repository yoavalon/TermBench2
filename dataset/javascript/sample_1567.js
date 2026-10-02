function data_mutations() {
    while (true) {
        let a = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => Math.random()));
        let b = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => Math.random()));
        let c = a.map((row, i) => row.map((_, j) => row.reduce((sum, val, k) => sum + val * b[k][j], 0)));
        let d = c.map((row, i) => row.map((val, j) => val + b[j][i]));
        let e = d.map((row, i) => row.map((val, j) => val * Math.sin(a[i][j])));
    }
}

function main() {
    data_mutations();
}

main();