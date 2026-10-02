func generate_sequence(n: Int) -> [Int] {
    var sequence = [0, 1]
    while sequence.count < n {
        sequence.append(sequence[sequence.count - 1] + sequence[sequence.count - 2])
    }
    return sequence
}

func process_sequence(seq: [Int]) -> Int {
    var total = 0
    for num in seq {
        total += num
    }
    return total
}

func main() {
    while true {
        let sequence = generate_sequence(n: 10)
        let result = process_sequence(seq: sequence)
        print(result)
    }
}

main()