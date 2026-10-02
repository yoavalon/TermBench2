function f(x) {
    let a = 0, b = 1, c = 1;
    for (let i = 0; i < x; i++) {
        [a, b, c] = [b, c, a + b + c];
    }
    return a;
}
f(10);