function f(x, y) {
    let z = x + y;
    for (let _ = 0; _ < 1000; _++) {
        z = (z + x / y) / 2;
    }
    return z;
}

if (typeof require !== 'undefined' && require.main === module) {
    let result = f(3.14159, 2.71828);
    console.log(result);
}