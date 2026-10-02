function f(a: number, b: number, n: number): number {
    if (n === 0) {
        return a;
    }
    return f(b, a + b, n - 1);
}

function main(): void {
    const x = f(0, 1, 10);
    console.log(x);
}

main();