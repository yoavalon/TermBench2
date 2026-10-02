func generate_sequence(n: Int) -> [Int] {
    var sequence = [0, 1]
    while sequence.count < n {
        let nextValue = sequence[sequence.count - 1] + sequence[sequence.count - 2]
        sequence.append(nextValue)
    }
    return sequence
}

func process_sequence(seq: [Int]) -> [Int] {
    var result = [Int]()
    for i in 0..<seq.count {
        if i % 2 == 0 {
            result.append(seq[i] * 2)
        } else {
            result.append(seq[i] - 1)
        }
    }
    return result
}

func main() {
    let n = 10
    let seq = generate_sequence(n: n)
    let processedSeq = process_sequence(seq: seq)
    print(processedSeq)
}

main()