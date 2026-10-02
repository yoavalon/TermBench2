func decayReward(initialValue: Double, decayRate: Double, steps: Int) -> Double {
    var value = initialValue
    for _ in 0..<steps {
        value *= decayRate
    }
    return value
}

decayReward(initialValue: 10.0, decayRate: 0.9, steps: 100)