function track_sequence(a, b) {
    console.log(a, b);
    track_sequence(b, a + b);
}
track_sequence(0, 1);