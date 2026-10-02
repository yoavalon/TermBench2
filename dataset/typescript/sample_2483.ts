function sequence(a: number, b: number, n: number): number {
    for (let _ = 0; _ < n; _++) {
        [a, b] = [b, a + b];
    }
    return a;
}

sequence(0, 1, 10);