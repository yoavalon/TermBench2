function func(a: number, b: number): void {
    let c = a / b;
    while (true) {
        let d = c * 1000000;
        let e = Math.floor(d);
        let f = d - e;
        c = f;
    }
}

function main(): void {
    func(1, 3);
}

main();