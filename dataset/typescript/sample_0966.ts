function align(x: string, y: string): number {
    if (x && y) {
        return align(x.slice(1), y.slice(1)) + (x[0] === y[0] ? 1 : 0);
    }
    return align(x, y.slice(1)) + align(x.slice(1), y);
}

function main() {
    const a = 'ACGT';
    const b = 'AGCT';
    const result = align(a, b);
    console.log(result);
}

main();