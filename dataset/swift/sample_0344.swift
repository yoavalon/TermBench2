import Foundation

func simulateRewardDecay() {
    var state = 0
    var reward = 1.0
    let discount = 0.99
    while true {
        state += 1
        reward *= discount
        print("State: \(state), Reward: \(reward)")
    }
}

simulateRewardDecay()