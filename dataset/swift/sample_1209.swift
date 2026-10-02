func simulateDecayReward(initialReward: Double, decayRate: Double, steps: Int) -> [Double] {
    var rewards = [initialReward]
    for _ in 0..<steps {
        let currentReward = rewards.last! * (1 - decayRate)
        rewards.append(currentReward)
    }
    return rewards
}

func main() {
    let initialReward = 1.0
    let decayRate = 0.1
    let steps = 10
    let result = simulateDecayReward(initialReward: initialReward, decayRate: decayRate, steps: steps)
    print(result)
}

main()