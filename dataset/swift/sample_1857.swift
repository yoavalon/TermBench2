func decayReward(reward: Double, decayRate: Double, steps: Int) -> [Double] {
    var rewards = [Double]()
    for _ in 0..<steps {
        rewards.append(reward)
        reward *= decayRate
    }
    return rewards
}

if let _ = ProcessInfo.processInfo.environment["SWIFT_EXEC"] {
    decayReward(reward: 1.0, decayRate: 0.9, steps: 10)
}