function calculate_precision_error(a, b) {
    let x = a + b;
    let y = a - b;
    let z = x * y;
    return Math.abs(z - Math.pow(a, 2) + Math.pow(b, 2));
}

function test_precision() {
    let data = [[1.0, 1.0], [1.0, 2.0], [1.0, 3.0], [1.0, 4.0], [1.0, 5.0], [2.0, 3.0], [3.0, 4.0], [4.0, 5.0], [5.0, 6.0], [6.0, 7.0]];
    let results = [];
    for (let i = 0; i < data.length; i++) {
        let [a, b] = data[i];
        let error = calculate_precision_error(a, b);
        results.push(error);
    }
    return results;
}

function main() {
    let precision_errors = test_precision();
    for (let idx = 0; idx < precision_errors.length; idx++) {
        console.log(`Error ${idx + 1}: ${precision_errors[idx]}`);
    }
}
main();