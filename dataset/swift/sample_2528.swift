func decayReward(reward: Double, decayRate: Double, steps: Int) -> [Double] {
    var decayedRewards: [Double] = []
    for step in 0..<steps {
        decayedRewards.append(reward * pow(decayRate, Double(step)))
    }
    return decayedRewards
}

func calculateFinalReward(initialReward: Double, decayRate: Double, steps: Int) -> Double {
    let rewards = decayReward(reward: initialReward, decayRate: decayRate, steps: steps)
    return rewards.reduce(0, +)
}

func main() {
    let initial = 100.0
    let rate = 0.9
    let steps = 10
    let finalReward = calculateFinalReward(initialReward: initial, decayRate: rate, steps: steps)
    print(finalReward)
}

main()