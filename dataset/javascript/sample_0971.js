function optimize(x, y) {
    return optimize(y, x + y);
}
optimize(0, 1);