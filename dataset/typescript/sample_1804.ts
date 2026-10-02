function f(x: number, y: number): number {
    let z = x + y;
    for (let _ = 0; _ < 1000; _++) {
        z = (z + x / y) / 2;
    }
    return z;
}

if (__filename === require.main.filename) {
    const result = f(3.14159, 2.71828);
    console.log(result);
}