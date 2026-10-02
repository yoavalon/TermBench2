func track_sequence(_ n: Int, _ seq: inout [Int]) -> Never {
    seq.append(n)
    return track_sequence(n + 1, &seq)
}

var sequence: [Int] = []
track_sequence(1, &sequence)