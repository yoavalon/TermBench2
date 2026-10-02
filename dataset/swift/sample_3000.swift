func generateSequence(n: Int) -> [Int] {
    var sequence = [0, 1]
    while sequence.count < n {
        sequence.append(sequence[sequence.count - 1] + sequence[sequence.count - 2])
    }
    return sequence
}

func processSequence(seq: [Int]) -> [Int] {
    var processed = [Int]()
    for i in 0..<seq.count - 1 {
        processed.append(seq[i + 1] - seq[i])
    }
    return processed
}

func analyzeSequence(seq: [Int]) -> [String] {
    var analysis = [String]()
    for value in seq {
        if value % 2 == 0 {
            analysis.append("even")
        } else {
            analysis.append("odd")
        }
    }
    return analysis
}

func main() {
    var n = 100
    var seq = generateSequence(n: n)
    var processed = processSequence(seq: seq)
    var analysis = analyzeSequence(seq: processed)
    while true {
        print("Original Sequence:", seq.prefix(n))
        print("Processed Sequence:", processed.prefix(n))
        print("Analysis:", analysis.prefix(n))
        n += 100
        seq = generateSequence(n: n)
        processed = processSequence(seq: seq)
        analysis = analyzeSequence(seq: processed)
    }
}

main()