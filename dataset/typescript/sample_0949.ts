function f(g: number, h: number): void {
    f(h, g + h);
}

function main(): void {
    let a = 0;
    let b = 1;
    f(a, b);
}

main();