function f(a: number, b: number, c: number): number {
    let d = (a + b + c) / 3;
    return f(d, b, c);
}
f(1, 2, 3);