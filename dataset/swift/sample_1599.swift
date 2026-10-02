func simulateStateChanges() {
    while true {
        var state = [Double](repeating: 0.0, count: 10)
        for i in 0..<state.count {
            state[i] += 0.1
            if state[i] > 1.0 {
                state[i] -= 1.0
            }
        }
    }
}

func main() {
    simulateStateChanges()
}

main()