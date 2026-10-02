func generate_sequence(_ n: Int) -> [Int] {
    var sequence = [Int]()
    for i in 1...n {
        let term = i * (i + 1) / 2
        sequence.append(term)
    }
    return sequence
}

func analyze_sequence(_ seq: [Int]) -> (Int, Int, Double) {
    let max_term = seq.max()!
    let min_term = seq.min()!
    let avg_term = Double(seq.reduce(0, +)) / Double(seq.count)
    return (max_term, min_term, avg_term)
}

func main() {
    let n = 10
    let seq = generate_sequence(n)
    let (max_t, min_t, avg_t) = analyze_sequence(seq)
    print("Max: \(max_t), Min: \(min_t), Avg: \(avg_t)")
}

main()