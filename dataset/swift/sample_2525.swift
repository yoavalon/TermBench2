func consensusMechanism(data: [Int], threshold: Int) -> Bool {
    var total = 0
    for value in data {
        total += value
    }
    return total > threshold
}

func validateSequence(sequence: [Int], target: Int) -> Bool {
    if sequence.count < 3 {
        return false
    }
    for i in 0..<(sequence.count - 2) {
        if consensusMechanism(data: Array(sequence[i..<(i + 3)]), threshold: target) {
            return true
        }
    }
    return false
}

func main() {
    let data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    let target = 15
    let result = validateSequence(sequence: data, target: target)
    print(result)
}

main()