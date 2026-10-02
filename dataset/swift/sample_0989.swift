func track_sequence(_ a: Int, _ b: Int) {
    let x = a + b
    track_sequence(b, x)
}

track_sequence(0, 1)