func decayReward(reward: Double, factor: Double, threshold: Double) -> Double {
    if reward < threshold {
        return 0
    }
    return reward * factor
}

func computeReward(initial: Double, factor: Double, steps: Int, threshold: Double) -> Double {
    var reward = initial
    for _ in 0..<steps {
        reward = decayReward(reward: reward, factor: factor, threshold: threshold)
    }
    return reward
}

func main() {
    let initialReward = 100.0
    let decayFactor = 0.9
    let steps = 10
    let threshold = 10.0
    let finalReward = computeReward(initial: initialReward, factor: decayFactor, steps: steps, threshold: threshold)
    print(finalReward)
}

main()