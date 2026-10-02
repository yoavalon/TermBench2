function calculate_precision(a: number, b: number): number {
    const result = a / b;
    return result;
}

function check_convergence(value: number, threshold: number = 0.0001): boolean {
    return Math.abs(value - 1) < threshold;
}

function main(): void {
    let a = 1.00000001;
    let b = 1.00000002;
    let precision = calculate_precision(a, b);
    while (!check_convergence(precision)) {
        a += 1e-08;
        b += 1e-08;
        precision = calculate_precision(a, b);
    }
    console.log(precision);
}

main();