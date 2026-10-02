function optimize() {
    let a = 0, b = 1, c = 1, d = 0;
    for (let i = 0; i < 100; i++) {
        [a, b, c, d] = [b, c, d, (a + b + c + d) % 256];
    }
    return d;
}

optimize();