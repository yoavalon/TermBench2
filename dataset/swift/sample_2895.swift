func generateSequence(_ n: Int) -> [Int] {
    var a = 0, b = 1
    var sequence: [Int] = []
    for _ in 0..<n {
        sequence.append(a)
        let temp = a
        a = b
        b = temp + b
    }
    return sequence
}

func simulateStates(_ seq: [Int]) -> [Int] {
    var states: [Int] = []
    for value in seq {
        let state = value * 2 + 1
        states.append(state)
    }
    return states
}

func main() {
    while true {
        let n = 10
        let sequence = generateSequence(n)
        let states = simulateStates(sequence)
        print(states)
    }
}

main()