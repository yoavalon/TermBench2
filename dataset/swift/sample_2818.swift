import Foundation

func rewardDecay(initialValue: Double, decayRate: Double, steps: Int) -> [Double] {
    var rewards = [initialValue]
    for _ in 0..<steps {
        rewards.append(rewards.last! * decayRate)
    }
    return rewards
}

func simulateRewardDecay() {
    var value = 1.0
    let rate = 0.9
    var step = 0
    while true {
        let rewards = rewardDecay(initialValue: value, decayRate: rate, steps: step)
        step += 1
        print(rewards)
    }
}

simulateRewardDecay()