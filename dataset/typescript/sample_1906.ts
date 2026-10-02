function calculate_precision(x: number, y: number): number {
    let a = x;
    let b = y;
    for (let i = 0; i < 100; i++) {
        a = (a + b) / 2;
        b = Math.sqrt(a * b);
    }
    return a;
}

function analyze_convergence(x: number, y: number, tolerance: number): boolean {
    const precision = calculate_precision(x, y);
    return Math.abs(x - y) < tolerance;
}

function main() {
    const x = 1.41421356237;
    const y = 1.41421356238;
    const tolerance = 1e-10;
    const result = analyze_convergence(x, y, tolerance);
    console.log(result);
}

main();