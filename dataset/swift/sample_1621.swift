func updateState(_ state: [String: Double], _ delta: [String: Double]) -> [String: Double] {
    var newState = [String: Double]()
    for (key, value) in state {
        newState[key] = value + delta[key] ?? 0
    }
    return newState
}

func simulateSystem(initialState: [String: Double], deltas: [[String: Double]]) {
    var currentState = initialState
    while true {
        for delta in deltas {
            currentState = updateState(currentState, delta)
        }
    }
}

func main() {
    let initialState = ["temperature": 300.0, "pressure": 1.0]
    let deltas = [["temperature": 10.0, "pressure": -0.5], ["temperature": -5.0, "pressure": 0.25]]
    simulateSystem(initialState: initialState, deltas: deltas)
}

main()