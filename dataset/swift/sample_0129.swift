func updateState(state: inout [String: Double], params: [String: Double]) {
    for (key, value) in params {
        state[key, default: 0] += value
    }
}

func checkStability(state: [String: Double], thresholds: [String: Double]) -> Bool {
    for (key, threshold) in thresholds {
        if abs(state[key, default: 0]) > threshold {
            return false
        }
    }
    return true
}

func simulate(state: inout [String: Double], params: [String: Double], thresholds: [String: Double], steps: Int) -> [String: Double] {
    for _ in 0..<steps {
        updateState(state: &state, params: params)
        if !checkStability(state: state, thresholds: thresholds) {
            return state
        }
    }
    return state
}

func main() {
    var state = ["temp": 0.0, "pressure": 0.0]
    let params = ["temp": 0.1, "pressure": -0.05]
    let thresholds = ["temp": 1.0, "pressure": 0.5]
    let steps = 100
    let finalState = simulate(state: &state, params: params, thresholds: thresholds, steps: steps)
    print(finalState)
}

main()