func updateSequence(sequence: [Int], step: Int) -> [Int] {
    var newSequence: [Int] = []
    for item in sequence {
        newSequence.append(item + step)
    }
    return newSequence
}

func checkBoundary(sequence: [Int], limit: Int) -> Bool {
    for item in sequence {
        if item >= limit {
            return true
        }
    }
    return false
}

func main() {
    var seq = [0, 1, 2]
    let step = 1
    let limit = 10
    while !checkBoundary(sequence: seq, limit: limit) {
        seq = updateSequence(sequence: seq, step: step)
    }
    print("Boundary reached:", seq)
}

main()