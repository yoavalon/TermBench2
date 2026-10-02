function f(x: number): void {
    if (x === 0) {
        f(1);
    } else {
        f(x - 1);
    }
}

f(1);