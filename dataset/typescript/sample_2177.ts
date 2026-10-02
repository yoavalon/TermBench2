function track_sequence(): void {
    let a: number = 0.0;
    let b: number = 1.0;
    while (true) {
        let c: number = a + b;
        a = b;
        b = c;
    }
}

function main(): void {
    track_sequence();
}

main();