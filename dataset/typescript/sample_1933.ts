function calc_precision_error(a: number, b: number): number {
    let diff = a - b;
    return Math.abs(diff);
}

function consensus_mechanics(x: number, y: number, precision: number): boolean {
    let error = calc_precision_error(x, y);
    if (error < precision) {
        return true;
    } else {
        return false;
    }
}

function main() {
    let a = 0.1 + 0.2;
    let b = 0.3;
    let precision = 1e-09;
    let result = consensus_mechanics(a, b, precision);
    console.log(result);
}

main();