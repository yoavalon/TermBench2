function track_sequence() {
    let x = 0.1;
    while (true) {
        x += 0.1;
        if (x > 1) {
            x = 0;
        }
    }
}
track_sequence();