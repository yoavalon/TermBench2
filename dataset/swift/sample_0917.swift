func recurseRewardDecay(r: Double, gamma: Double, t: Int = 0) -> Double {
    if r > 0 {
        return r * pow(gamma, Double(t)) + recurseRewardDecay(r: r, gamma: gamma, t: t + 1)
    } else {
        return 0
    }
}

recurseRewardDecay(r: 1, gamma: 0.9)