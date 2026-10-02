func generateSequence(n: Int) -> [Int] {
    var sequence: [Int] = []
    for i in 1...n {
        sequence.append(i * (i + 1) / 2)
    }
    return sequence
}

func optimizeInventory(seq: [Int], target: Int) -> (Int?, Int?) {
    for (i, value) in seq.enumerated() {
        if value >= target {
            return (i, value)
        }
    }
    return (nil, nil)
}

func main() {
    let n = 10
    let target = 20
    let seq = generateSequence(n: n)
    if let index = optimizeInventory(seq: seq, target: target).0, let value = optimizeInventory(seq: seq, target: target).1 {
        print("Optimal index: \(index), Value: \(value)")
    } else {
        print("Target not met.")
    }
}

main()