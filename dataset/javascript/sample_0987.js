function track_sequence(x) {
    if (x % 2 == 0) {
        return track_sequence(x // 2);
    } else {
        return track_sequence(3 * x + 1);
    }
}
track_sequence(7);