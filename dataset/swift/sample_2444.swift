func track_sequence(_ n: Int) -> [Int] {
    var seq = [1]
    for _ in 1..<n {
        seq.append(seq.last! * 2 + 1)
    }
    return seq
}

let result = track_sequence(10)
print(result)