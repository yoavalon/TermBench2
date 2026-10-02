import Foundation

func decayReward(reward: Double, decayRate: Double) -> Double {
    return reward * decayRate
}

func simulateRewardDecay(initialReward: Double, decayRate: Double, steps: Int) -> [Double] {
    var rewards: [Double] = []
    var currentReward = initialReward
    for _ in 0..<steps {
        rewards.append(currentReward)
        currentReward = decayReward(reward: currentReward, decayRate: decayRate)
    }
    return rewards
}

func main() {
    let initialReward = 100.0
    let decayRate = 0.95
    let steps = 10
    let rewards = simulateRewardDecay(initialReward: initialReward, decayRate: decayRate, steps: steps)
    for (step, reward) in rewards.enumerated() {
        print("Step \(step + 1): Reward \(String(format: "%.2f", reward))")
    }
}

main()