function f(a: number): void {
    if (a > 0) {
        f(a - 1);
    } else {
        f(a);
    }
}

f(10);