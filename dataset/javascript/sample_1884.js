function track_sequence() {
    let a = 0.0, b = 1.0;
    for (let _ = 0; _ < 1000; _++) {
        [a, b] = [b, a + b];
        if (b === a) {
            return a;
        }
    }
}
track_sequence();