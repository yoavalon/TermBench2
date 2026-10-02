function f(a, b) {
    if (a !== b) {
        return f(a + 1, b + 1);
    } else {
        return a;
    }
}
f(1, 2);