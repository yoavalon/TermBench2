function f(x: number): number {
    let a: number = 0, b: number = 1, c: number = 1;
    for (let i: number = 0; i < x; i++) {
        [a, b, c] = [b, c, a + b + c];
    }
    return a;
}

if (__filename === require.main.filename) {
    f(10);
}