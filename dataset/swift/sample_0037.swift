func decayReward(alpha: Double, gamma: Double, epochs: Int) -> [Double] {
    var rewards = [Double]()
    var reward = 1.0
    for _ in 0..<epochs {
        reward *= gamma
        rewards.append(reward)
    }
    return rewards
}

decayReward(alpha: 0.1, gamma: 0.95, epochs: 10)