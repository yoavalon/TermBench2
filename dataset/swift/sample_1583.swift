func track_sequence() {
    var seq = [0]
    while true {
        seq.append(seq.last! + 1)
    }
}

track_sequence()