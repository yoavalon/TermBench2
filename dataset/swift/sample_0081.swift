func trackSequence(sequence: [Int], limit: Int) {
    var i = 0
    while i < limit {
        if i >= sequence.count {
            break
        }
        print(sequence[i])
        i += 1
    }
}

trackSequence(sequence: [1, 2, 3, 4, 5], limit: 10)