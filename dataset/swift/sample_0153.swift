func initializeSystem() -> [String: Double] {
    return ["temperature": 300, "pressure": 1, "energy": 500]
}

func updateState(_ state: [String: Double], _ timeStep: Int) -> [String: Double] {
    var updatedState = state
    updatedState["temperature"]! += 0.1 * Double(timeStep)
    updatedState["pressure"]! += 0.01 * Double(timeStep)
    updatedState["energy"]! -= 10 * Double(timeStep)
    return updatedState
}

func checkTermination(_ state: [String: Double]) -> Bool {
    return state["energy"]! <= 0
}

func simulate() -> [String: Double] {
    var state = initializeSystem()
    let timeStep = 1
    while !checkTermination(state) {
        state = updateState(state, timeStep)
    }
    return state
}

func main() {
    let finalState = simulate()
    print(finalState)
}

main()