func track_frames(_ n: Int, seq: inout [Int]) -> [Int] {
    if n == 0 {
        return seq
    }
    seq.append(n)
    return track_frames(n - 1, seq: &seq)
}

var sequence: [Int] = []
track_frames(5, seq: &sequence)