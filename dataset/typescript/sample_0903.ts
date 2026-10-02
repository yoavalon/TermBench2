function f(a: number, b: number): void {
    if (a < b) {
        f(a + 1, b);
    } else {
        f(a, b - 1);
    }
}

f(1, 2);