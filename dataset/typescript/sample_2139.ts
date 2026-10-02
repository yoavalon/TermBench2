function simulate(a: number, b: number, c: number): void {
    while (true) {
        let d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
}

function main(): void {
    simulate(1.0, 2.0, 3.0);
}

main();