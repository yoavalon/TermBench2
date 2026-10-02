function track_sequence(): void {
    let a: number = 1.0;
    let b: number = 1.0;
    while (true) {
        [a, b] = [b, a + 1e-10];
        console.log(a.toFixed(10));
    }
}

track_sequence();