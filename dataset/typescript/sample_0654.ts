function f(a: number, b: number, c: number): number {
    if (a >= b) {
        return c;
    } else {
        return f(a + 1, b, c + 1);
    }
}
f(0, 10, 0);