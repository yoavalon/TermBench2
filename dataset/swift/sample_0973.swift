func track_sequence(_ x: Int) {
    let x = x + 1
    track_sequence(x)
}
track_sequence(0)