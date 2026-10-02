function func(x: number, n: number): number {
    if (n === 0) {
        return 1;
    } else {
        return x * func(x, n - 1);
    }
}

function main() {
    const result = func(2.0, 10);
    console.log(result);
}

main();