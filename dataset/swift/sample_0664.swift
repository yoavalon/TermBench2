func rewardDecay(reward: Double, discount: Double, threshold: Double) -> Double {
    if reward < threshold {
        return reward
    } else {
        return rewardDecay(reward: reward * discount, discount: discount, threshold: threshold)
    }
}

rewardDecay(reward: 100, discount: 0.9, threshold: 10)