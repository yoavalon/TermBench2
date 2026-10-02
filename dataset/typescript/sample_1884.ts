function track_sequence(): number {
    let a: number = 0.0;
    let b: number = 1.0;
    for (let _ = 0; _ < 1000; _++) {
        [a, b] = [b, a + b];
        if (b === a) {
            return a;
        }
    }
    return a; // To ensure the function always returns a value
}

track_sequence();