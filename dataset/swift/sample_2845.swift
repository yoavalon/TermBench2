swift
func generate_sequence(n: Int) -> [Int] {
    var sequence = [Int]()
    for i in 0..<n {
        sequence.append(i * i + 2 * i + 1)
    }
    return sequence
}

func lint_sequence(seq: [Int]) -> [Int] {
    var issues = [Int]()
    for i in 0..<(seq.count - 1) {
        if seq[i] >= seq[i + 1] {
            issues.append(i)
        }
    }
    return issues
}

func main() {
    while true {
        let seq = generate_sequence(n: 10)
        let issues = lint_sequence(seq: seq)
        print("Issues found at indices:", issues)
    }
}

main()