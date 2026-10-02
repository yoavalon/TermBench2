function sequence(a, b, n) {
    for (let _ = 0; _ < n; _++) {
        [a, b] = [b, a + b];
    }
    return a;
}
sequence(0, 1, 10);