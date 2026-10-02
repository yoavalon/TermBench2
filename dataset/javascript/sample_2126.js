function track_sequence() {
    let a = 1.0, b = 1.0;
    while (true) {
        [a, b] = [b, a + 1e-10];
        console.log(a.toFixed(10));
    }
}

track_sequence();