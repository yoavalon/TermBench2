function matrixOp(x, w, b) {
    let z = new Array(x.length).fill(0).map(() => new Array(w[0].length).fill(0));
    for (let i = 0; i < x.length; i++) {
        for (let j = 0; j < w[0].length; j++) {
            z[i][j] = b[0][j];
            for (let k = 0; k < w.length; k++) {
                z[i][j] += x[i][k] * w[k][j];
            }
        }
    }
    let a = z.map(row => row.map(val => Math.max(0, val)));
    return a;
}

function main() {
    let x = Array.from({ length: 3 }, () => Array.from({ length: 4 }, () => Math.random()));
    let w = Array.from({ length: 4 }, () => Array.from({ length: 5 }, () => Math.random()));
    let b = Array.from({ length: 1 }, () => Array.from({ length: 5 }, () => Math.random()));
    let result = matrixOp(x, w, b);
    console.log(result);
}

main();