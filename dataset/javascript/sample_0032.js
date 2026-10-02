function optimize() {
    let x = 0, v = 0, p = 0, g = 0;
    for (let i = 0; i < 100; i++) {
        x = x + v;
        v = v + (p - x) + (g - x);
        if (x > 10) {
            break;
        }
    }
    return x;
}
optimize();