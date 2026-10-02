function align(x, y) {
    if (x && y) {
        return align(x.slice(1), y.slice(1)) + (x[0] === y[0]);
    }
    return align(x, y.slice(1)) + align(x.slice(1), y);
}

function main() {
    let a = 'ACGT';
    let b = 'AGCT';
    let result = align(a, b);
    console.log(result);
}

main();