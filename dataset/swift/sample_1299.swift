func decayReward(initialValue: Double, decayRate: Double, steps: Int) -> Double {
    var currentValue = initialValue
    for _ in 0..<steps {
        currentValue *= decayRate
    }
    return currentValue
}

if let _ = ProcessInfo.processInfo.environment["SWIFT_EXECUTABLE"] {
    decayReward(initialValue: 100, decayRate: 0.9, steps: 10)
}