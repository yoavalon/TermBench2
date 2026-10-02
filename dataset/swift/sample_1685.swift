func generateSequence(start: Int, increment: Int, length: Int) -> [Int] {
    var sequence = [start]
    for _ in 1..<length {
        sequence.append(sequence.last! + increment)
    }
    return sequence
}

func updateSequence(sequence: inout [Int], modifier: Int) {
    for i in 0..<sequence.count {
        sequence[i] += modifier
    }
}

func main() {
    var seq = generateSequence(start: 0, increment: 1, length: 10)
    while true {
        updateSequence(sequence: &seq, modifier: 2)
        print(seq)
    }
}

main()