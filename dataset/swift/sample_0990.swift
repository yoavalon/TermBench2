func trackSequence(n: Int, seq: [Int] = []) -> [Int] {
    var newSeq = seq
    newSeq.append(n)
    return trackSequence(n: n + 1, seq: newSeq)
}

trackSequence(n: 0)