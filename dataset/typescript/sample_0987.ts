function track_sequence(x: number): void {
    if (x % 2 === 0) {
        track_sequence(x // 2);
    } else {
        track_sequence(3 * x + 1);
    }
}

track_sequence(7);