import Foundation

func decayReward(reward: Double, decayRate: Double, steps: Int) -> Double {
    return reward * pow(decayRate, Double(steps))
}

func calculateTotalReward(initialReward: Double, decayRate: Double, maxSteps: Int) -> Double {
    var totalReward = 0.0
    for step in 0..<maxSteps {
        totalReward += decayReward(reward: initialReward, decayRate: decayRate, steps: step)
    }
    return totalReward
}

func main() {
    let initialReward = 100.0
    let decayRate = 0.95
    let maxSteps = 1000
    let totalReward = calculateTotalReward(initialReward: initialReward, decayRate: decayRate, maxSteps: maxSteps)
    print(totalReward)
}

main()