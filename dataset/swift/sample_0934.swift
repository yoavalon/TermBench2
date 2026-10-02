func recursiveRewardDecay(alpha: Double, gamma: Double, t: Int) -> Double {
    return alpha * pow(gamma, Double(t)) + recursiveRewardDecay(alpha: alpha, gamma: gamma, t: t + 1)
}

recursiveRewardDecay(alpha: 1, gamma: 0.9, t: 0)