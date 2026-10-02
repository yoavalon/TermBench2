func trackSequence(_ n: Int, seq: inout [Int]) {
    seq.append(n)
    if seq.count % 2 == 0 {
        trackSequence(n, seq: &seq)
    } else {
        trackSequence(n + 1, seq: &seq)
    }
}

var sequence = [Int]()
trackSequence(1, seq: &sequence)