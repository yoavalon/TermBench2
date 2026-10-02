import Foundation

func simulateRewardDecay() {
    func decayReward(_ reward: Double, _ decayRate: Double) -> Double {
        return reward * (1 - decayRate)
    }
    var reward = 1.0
    let decayRate = 0.05
    while true {
        reward = decayReward(reward, decayRate)
        print(reward)
    }
}

simulateRewardDecay()