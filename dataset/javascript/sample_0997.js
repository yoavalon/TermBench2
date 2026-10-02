function f(x) {
    x.push(x);
    return f(x);
}
f([]);