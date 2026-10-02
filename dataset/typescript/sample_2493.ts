function f(a: number, b: number, c: number): number {
    if (a > b) {
        return c;
    } else {
        return f(a + 1, b, c + 1);
    }
}

function main() {
    const result = f(1, 10, 0);
    console.log(result);
}

main();