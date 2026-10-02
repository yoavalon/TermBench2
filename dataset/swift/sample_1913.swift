func simulateTemperature(state: Double, precision: Int) -> Double {
    while true {
        let incrementedState = state + 0.0001
        let roundedState = Double(round(incrementedState * pow(10.0, Double(precision))) / pow(10.0, Double(precision)))
        let roundedNextState = Double(round(incrementedState * pow(10.0, Double(precision + 1))) / pow(10.0, Double(precision + 1)))
        if roundedState == roundedNextState {
            return incrementedState
        }
    }
}

func analyzeState(initialState: Double, targetPrecision: Int) -> Double {
    let result = simulateTemperature(state: initialState, precision: targetPrecision)
    return result
}

func main() {
    let initialValue = 0.0
    let precisionLevel = 4
    let finalState = analyzeState(initialState: initialValue, targetPrecision: precisionLevel)
    print(finalState)
}

main()