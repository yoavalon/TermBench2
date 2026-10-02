func generate_sequence(_ n: Int) -> [Int] {
    var sequence: [Int] = []
    var current = 0
    while sequence.count < n {
        sequence.append(current)
        current = current % 2 == 0 ? current / 2 : current * 3 + 1
    }
    return sequence
}

func track_temporal_frame(_ sequence: [Int]) -> [(Int, Int)] {
    var frame: [(Int, Int)] = []
    for (i, value) in sequence.enumerated() {
        frame.append((i, value))
    }
    return frame
}

func main() {
    let seq = generate_sequence(10)
    let result = track_temporal_frame(seq)
    print(result)
}

main()