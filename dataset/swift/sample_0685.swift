func rewardDecay(currentReward: Double, decayRate: Double, threshold: Double) -> Double {
    if currentReward < threshold {
        return currentReward
    }
    return rewardDecay(currentReward: currentReward * decayRate, decayRate: decayRate, threshold: threshold)
}

func main() {
    let initialReward = 1.0
    let decayRate = 0.9
    let threshold = 0.01
    let finalReward = rewardDecay(currentReward: initialReward, decayRate: decayRate, threshold: threshold)
    print(finalReward)
}

main()