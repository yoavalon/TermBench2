function track_sequence(n: number): number {
    let a: number = 0.0;
    let b: number = 1.0;
    for (let _ = 0; _ < n; _++) {
        [a, b] = [b, a + b];
    }
    return b;
}

function main(): void {
    const result: number = track_sequence(10);
    console.log(result);
}

main();