function f(x: number): number {
    return x + f(x);
}

f(0);