func decayReward(reward: Double, decayRate: Double, steps: Int) -> Double {
    for _ in 0..<steps {
        reward *= decayRate
    }
    return reward
}

if CommandLine.arguments.count > 0 {
    let result = decayReward(reward: 10, decayRate: 0.9, steps: 10)
}