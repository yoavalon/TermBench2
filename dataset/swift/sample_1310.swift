import Foundation

func calculateRewardDecay(initialReward: Double, decayRate: Double, timeSteps: Int) -> [Double] {
    var rewards = [Double](repeating: 0.0, count: timeSteps)
    rewards[0] = initialReward
    for t in 1..<timeSteps {
        rewards[t] = rewards[t - 1] * (1 - decayRate)
    }
    return rewards
}

func simulateTerminalCondition(rewards: [Double], threshold: Double) -> Bool {
    for reward in rewards {
        if reward < threshold {
            return true
        }
    }
    return false
}

func main() {
    let initialReward = 1.0
    let decayRate = 0.05
    let timeSteps = 20
    let threshold = 0.01
    let rewards = calculateRewardDecay(initialReward: initialReward, decayRate: decayRate, timeSteps: timeSteps)
    let terminalCondition = simulateTerminalCondition(rewards: rewards, threshold: threshold)
    print("Terminal Condition Met:", terminalCondition)
}

main()