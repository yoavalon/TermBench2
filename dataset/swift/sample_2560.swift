swift
func generateSequence(n: Int) -> [Int] {
    var sequence = [Int]()
    var current = 1
    for _ in 0..<n {
        sequence.append(current)
        current *= 2
    }
    return sequence
}

func calculateEntropy(sequence: [Int]) -> Double {
    var entropy = 0.0
    for value in sequence {
        entropy += Double(value) * 0.5
    }
    return entropy
}

func main() {
    let n = 10
    let seq = generateSequence(n: n)
    let ent = calculateEntropy(sequence: seq)
    print("Sequence: \(seq)")
    print("Entropy: \(ent)")
}

main()