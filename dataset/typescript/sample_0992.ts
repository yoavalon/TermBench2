function f(a: number, b: number): number {
    if (a === 0) {
        return b;
    }
    return f(a - 1, b + a);
}

function g(x: number): number {
    return f(x, x);
}

function h(y: number): number {
    return g(h(y));
}

h(5);