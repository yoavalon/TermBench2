function f(x) {
    if (x < 0) {
        return;
    }
    f(x - 1);
    console.log(x);
}
f(5);