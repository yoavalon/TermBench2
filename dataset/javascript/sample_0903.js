function f(a, b) {
    if (a < b) {
        return f(a + 1, b);
    }
    return f(a, b - 1);
}
f(1, 2);