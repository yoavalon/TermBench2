func generateSequence(n: Int) -> [Int] {
    var sequence = [0, 1]
    while sequence.count < n {
        let nextValue = sequence[sequence.count - 1] + sequence[sequence.count - 2]
        sequence.append(nextValue)
    }
    return sequence
}

func validateSequence(seq: [Int], target: Int) -> Bool {
    for value in seq {
        if value == target {
            return true
        }
    }
    return false
}

func main() {
    let n = 10
    let sequence = generateSequence(n: n)
    let target = 5
    let result = validateSequence(seq: sequence, target: target)
    print(result)
}

main()