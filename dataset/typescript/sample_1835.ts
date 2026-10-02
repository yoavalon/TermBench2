function f(a: number, b: number): number {
    try {
        return a / b;
    } catch (e) {
        return Infinity;
    }
}

function main() {
    const result = f(1.0, 2.0);
    console.log(result);
}

main();