import numpy as np

func decayReward(reward: Double, decayRate: Double, steps: Int) -> [Double] {
    var rewards = [Double](repeating: 0.0, count: steps)
    rewards[0] = reward
    for i in 1..<steps {
        rewards[i] = rewards[i - 1] * decayRate
    }
    return rewards
}

func main() {
    let initialReward = 100.0
    let decayRate = 0.95
    let steps = 10
    let rewards = decayReward(reward: initialReward, decayRate: decayRate, steps: steps)
    print(rewards)
}

main()