func generate_sequence(n: Int, a: Int = 0, b: Int = 1) -> [Int] {
    var sequence = [a, b]
    for _ in 0..<(n - 2) {
        let nextValue = sequence.last! + sequence[sequence.count - 2]
        sequence.append(nextValue)
    }
    return sequence
}

func analyze_sequence(seq: [Int]) -> (Int, Double) {
    let maxValue = seq.max()!
    let avgValue = Double(seq.reduce(0, +)) / Double(seq.count)
    return (maxValue, avgValue)
}

func main() {
    let n = 10
    let seq = generate_sequence(n: n)
    let (maxVal, avgVal) = analyze_sequence(seq: seq)
    print("Max Value: \(maxVal), Average Value: \(avgVal)")
}

main()