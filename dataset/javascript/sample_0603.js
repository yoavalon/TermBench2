function track_sequence(n, a = 0, b = 1) {
    if (n == 0) {
        return a;
    }
    return track_sequence(n - 1, b, a + b);
}

track_sequence(10);