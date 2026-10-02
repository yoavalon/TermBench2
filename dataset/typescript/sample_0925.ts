function f(a: number, b: number): number {
    if (a !== b) {
        return f(a + 1, b + 1);
    } else {
        return a;
    }
}

f(1, 2);