function calculate_precision_error(a: number, b: number): number {
    let x = a + b;
    let y = a - b;
    let z = x * y;
    return Math.abs(z - a ** 2 + b ** 2);
}

function test_precision(): number[] {
    let data = [[1.0, 1.0], [1.0, 2.0], [1.0, 3.0], [1.0, 4.0], [1.0, 5.0], [2.0, 3.0], [3.0, 4.0], [4.0, 5.0], [5.0, 6.0], [6.0, 7.0]];
    let results: number[] = [];
    for (let [a, b] of data) {
        let error = calculate_precision_error(a, b);
        results.push(error);
    }
    return results;
}

function main(): void {
    let precision_errors = test_precision();
    for (let idx = 0; idx < precision_errors.length; idx++) {
        console.log(`Error ${idx + 1}: ${precision_errors[idx]}`);
    }
}

main();