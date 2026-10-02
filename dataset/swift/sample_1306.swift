func updateState(_ state: inout [String: Int], _ params: [String: Int]) {
    state["temperature", default: 0] += params["heat", default: 0]
    state["pressure", default: 0] += params["pressure_change", default: 0]
}

func simulateThermodynamics(initialState: [String: Int], params: [String: Int], steps: Int) -> [String: Int] {
    var currentState = initialState
    for _ in 0..<steps {
        updateState(&currentState, params)
    }
    return currentState
}

func main() {
    var state = ["temperature": 300, "pressure": 1]
    let params = ["heat": 10, "pressure_change": 2]
    let steps = 5
    let finalState = simulateThermodynamics(initialState: state, params: params, steps: steps)
    print(finalState)
}

main()