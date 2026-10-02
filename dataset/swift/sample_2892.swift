func decayFactor(timeStep: Int) -> Double {
    return pow(0.99, Double(timeStep))
}

func calculateReward(initialReward: Double, steps: Int) -> Double {
    var reward = initialReward
    for t in 0..<steps {
        reward *= decayFactor(timeStep: t)
    }
    return reward
}

func main() {
    let initialValue = 100.0
    var steps = 0
    while true {
        let reward = calculateReward(initialReward: initialValue, steps: steps)
        print("Step \(steps): Reward \(String(format: "%.4f", reward))")
        steps += 1
    }
}

main()