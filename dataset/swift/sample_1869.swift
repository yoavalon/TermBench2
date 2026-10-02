func rewardDecay(initialReward: Double, decayRate: Double, steps: Int) -> [Double] {
    var rewards: [Double] = []
    var currentReward = initialReward
    for _ in 0..<steps {
        rewards.append(currentReward)
        currentReward *= decayRate
    }
    return rewards
}

if CommandLine.arguments.count > 0 {
    rewardDecay(initialReward: 1.0, decayRate: 0.95, steps: 10)
}