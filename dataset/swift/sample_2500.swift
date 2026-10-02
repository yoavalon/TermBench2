func simulateDecay(steps: Int, decayRate: Double) -> [Double] {
    var reward = 1.0
    var rewards: [Double] = []
    for _ in 0..<steps {
        rewards.append(reward)
        reward *= decayRate
    }
    return rewards
}

func main() {
    print(simulateDecay(steps: 10, decayRate: 0.9))
}

main()