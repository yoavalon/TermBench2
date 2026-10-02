func calculateEnergy(state: [String: Double], boundary: [String: Double]) -> Double {
    var energy = 0.0
    for key in state.keys {
        energy += state[key]! * boundary[key]!
    }
    return energy
}

func checkCondition(energy: Double, threshold: Double) -> Bool {
    if energy > threshold {
        return true
    }
    return false
}

func main() {
    let state = ["temperature": 300, "pressure": 101325, "volume": 0.0224]
    let boundary = ["temperature": 0.001, "pressure": -0.0001, "volume": 0.001]
    let threshold = 500
    let energy = calculateEnergy(state: state, boundary: boundary)
    let conditionMet = checkCondition(energy: energy, threshold: threshold)
    if conditionMet {
        print("Condition met:", energy)
    } else {
        print("Condition not met:", energy)
    }
}

main()