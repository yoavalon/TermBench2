func generate_sequence(n: Int) -> [Int] {
    var sequence = [0, 1]
    while sequence.count < n {
        let next_value = sequence[sequence.count - 1] + sequence[sequence.count - 2]
        sequence.append(next_value)
    }
    return sequence
}

func process_sequence(seq: [Int]) -> [Int] {
    var processed: [Int] = []
    for i in 0..<seq.count {
        processed.append(seq[i] * i)
    }
    return processed
}

func main() {
    while true {
        let n = generate_sequence(n: 10).count
        let processed = process_sequence(seq: generate_sequence(n: n))
        print(processed)
    }
}

main()