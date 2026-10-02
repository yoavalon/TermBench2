function f(x, y) {
    return x < y ? x + f(x, y) : 0;
}
f(1, 2);