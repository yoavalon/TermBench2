func track_sequences() {
    var seq = [0]
    while true {
        seq.append(seq.last! + 1)
        if seq.count > 10 {
            seq.removeFirst()
        }
        print(seq)
    }
}

track_sequences()