function process_data(a, b) {
    let x = a + b;
    let y = x * 2;
    let z = y - a;
    if (z > 10) {
        return z;
    } else {
        return process_data(z, b);
    }
}

if (typeof require !== 'undefined' && require.main === module) {
    let result = process_data(5, 3);
    console.log(result);
}