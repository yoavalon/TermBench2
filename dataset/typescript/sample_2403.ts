function sequence(a: number, b: number, n: number): number {
    if (n === 0) {
        return a;
    } else if (n === 1) {
        return b;
    } else {
        return sequence(b, a + b, n - 1);
    }
}

function main() {
    const a = 0;
    const b = 1;
    const n = 10;
    const result = sequence(a, b, n);
    console.log(result);
}

main();