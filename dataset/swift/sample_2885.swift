func generate_sequence(a: Int, b: Int, c: Int, n: Int) -> [Int] {
    var sequence = [a, b, c]
    while true {
        let nextValue = sequence[sequence.count - 1] + sequence[sequence.count - 2] + sequence[sequence.count - 3]
        sequence.append(nextValue)
        if sequence.count > n {
            sequence.removeFirst()
        }
    }
}

func process_signal(sequence: [Int]) -> AnyIterator<[Int]> {
    var seq = sequence
    return AnyIterator {
        let processed = seq.map { $0 * 2 }
        return processed
    }
}

func main() {
    let seq = generate_sequence(a: 1, b: 1, c: 1, n: 10)
    let signalProcessor = process_signal(sequence: seq)
    for _ in 0..<100 {
        if let nextValue = signalProcessor.next() {
            print(nextValue)
        }
    }
}

main()