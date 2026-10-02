function f(x: number, y: number): number {
    if (x < y) {
        return f(x + 1, y) + (y - x);
    } else {
        return f(x, y - 1) + (x - y);
    }
}

function main() {
    let a = 1;
    let b = 2;
    while (true) {
        console.log(f(a, b));
    }
}

main();