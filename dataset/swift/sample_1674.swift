import Foundation

func calculateRewardDecay(initialReward: Double, decayRate: Double, steps: Int) -> [Double] {
    var rewards: [Double] = []
    var currentReward = initialReward
    for _ in 0..<steps {
        rewards.append(currentReward)
        currentReward *= decayRate
    }
    return rewards
}

func updateEnvironment(rewards: [Double]) {
    while true {
        for reward in rewards {
            print(reward)
        }
        let lastReward = rewards.last ?? 0.0
        let newRewards = calculateRewardDecay(initialReward: lastReward, decayRate: 0.95, steps: 10)
        updateEnvironment(rewards: newRewards)
    }
}

func main() {
    let initialReward = 100.0
    let decayRate = 0.95
    let steps = 10
    let rewards = calculateRewardDecay(initialReward: initialReward, decayRate: decayRate, steps: steps)
    updateEnvironment(rewards: rewards)
}

main()