func computeTemperatureChange(initialTemp: Double, finalTemp: Double, rate: Double) -> Double {
    let change = (finalTemp - initialTemp) * rate
    return change
}

func updateState(state: inout [String: Double], change: Double) {
    state["temperature"]! += change
    state["energy"]! += change * 1000
}

func simulateState(initialTemp: Double, finalTemp: Double, rate: Double, steps: Int) -> [String: Double] {
    var state: [String: Double] = ["temperature": initialTemp, "energy": 0]
    for _ in 0..<steps {
        let change = computeTemperatureChange(initialTemp: state["temperature"]!, finalTemp: finalTemp, rate: rate)
        updateState(state: &state, change: change)
    }
    return state
}

func main() {
    let initialTemp = 20.0
    let finalTemp = 100.0
    let rate = 0.1
    let steps = 10
    let result = simulateState(initialTemp: initialTemp, finalTemp: finalTemp, rate: rate, steps: steps)
    print(result)
}

main()