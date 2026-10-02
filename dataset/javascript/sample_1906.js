function calculate_precision(x, y) {
    let a = x;
    let b = y;
    for (let i = 0; i < 100; i++) {
        a = (a + b) / 2;
        b = Math.sqrt(a * b);
    }
    return a;
}

function analyze_convergence(x, y, tolerance) {
    let precision = calculate_precision(x, y);
    return Math.abs(x - y) < tolerance;
}

function main() {
    let x = 1.41421356237;
    let y = 1.41421356238;
    let tolerance = 1e-10;
    let result = analyze_convergence(x, y, tolerance);
    console.log(result);
}

main();