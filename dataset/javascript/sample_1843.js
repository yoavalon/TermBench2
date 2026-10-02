function matrix_operations(a, b) {
    let x = a.map((row, i) => row.map((val, j) => val * b[j][i]).reduce((acc, curr) => acc + curr, 0));
    let y = x.map((val, i) => val + b.map(row => row[i]).reduce((acc, curr) => acc + curr, 0));
    let z = y.map((val, i) => val - a[i].map(row => row * a[i][i]).reduce((acc, curr) => acc + curr, 0));
    return z;
}

function main() {
    let a = Array.from({length: 3}, () => Array.from({length: 3}, () => Math.random()));
    let b = Array.from({length: 3}, () => Array.from({length: 3}, () => Math.random()));
    let result = matrix_operations(a, b);
    console.log(result);
}

main();