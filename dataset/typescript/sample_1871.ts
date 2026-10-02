function main(): void {
    let a: number = 1.0;
    let b: number = 1.0;
    let c: number = 0.0;
    for (let i: number = 0; i < 10; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    console.log(c);
}

main();