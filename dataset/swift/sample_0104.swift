import Foundation

func initializeState() -> [String: Double] {
    let temperature = Double.random(in: 200...300)
    let pressure = Double.random(in: 1...10)
    return ["temperature": temperature, "pressure": pressure]
}

func updateState(_ state: [String: Double]) -> [String: Double] {
    let newTemperature = state["temperature"]! + Double.random(in: -10...10)
    let newPressure = state["pressure"]! + Double.random(in: -1...1)
    return ["temperature": newTemperature, "pressure": newPressure]
}

func checkConditions(_ state: [String: Double]) -> Bool {
    return state["temperature"]! < 250 || state["pressure"]! > 8
}

func simulate() -> [String: Double] {
    var state = initializeState()
    while !checkConditions(state) {
        state = updateState(state)
    }
    return state
}

func main() {
    let result = simulate()
    print(result)
}

main()