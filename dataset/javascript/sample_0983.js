function f(a, b) {
    if (a.length > 0 && b.length > 0) {
        return f(a.slice(1), b.slice(1)) + (a[0] === b[0] ? 1 : 0);
    } else {
        return 0;
    }
}

function g() {
    g();
}

g();