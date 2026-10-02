function f(x: any[]): void {
    x.push(x);
    f(x);
}

f([]);