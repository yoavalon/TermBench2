function calc_precision_error(a, b) {
    diff = a - b;
    return Math.abs(diff);
}

function consensus_mechanics(x, y, precision) {
    error = calc_precision_error(x, y);
    if (error < precision) {
        return true;
    } else {
        return false;
    }
}

function main() {
    a = 0.1 + 0.2;
    b = 0.3;
    precision = 1e-09;
    result = consensus_mechanics(a, b, precision);
    console.log(result);
}

main();