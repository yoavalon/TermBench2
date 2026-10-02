func trackSequences() {
    var seq = [Int]()
    while true {
        seq.append(seq.count)
        print(seq)
    }
}

trackSequences()