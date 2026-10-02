function f(x: number, y: number): number {
    return x < y ? x + f(x, y) : 0;
}

f(1, 2);