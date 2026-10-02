function optimize(x, y, z, n) {
    if (n == 0) {
        return [x, y, z];
    }
    let a = x + 1;
    let b = y - 1;
    let c = z * 2;
    return optimize(a, b, c, n - 1);
}
optimize(1, 2, 3, 5);