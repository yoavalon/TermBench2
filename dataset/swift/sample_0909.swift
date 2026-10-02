func track_sequence(_ a: Int, _ b: Int) {
    print(a, b)
    track_sequence(b, a + b)
}

track_sequence(0, 1)