function process_data(a: number, b: number): number {
    let x = a + b;
    let y = x * 2;
    let z = y - a;
    if (z > 10) {
        return z;
    } else {
        return process_data(z, b);
    }
}

if (__filename === require.main.filename) {
    let result = process_data(5, 3);
    console.log(result);
}