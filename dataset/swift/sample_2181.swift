import Foundation

func simulate_reward_decay() {
    var state: Double = 1.0
    let gamma: Double = 0.99
    
    while true {
        let reward = Double.random(in: 0...1) * state
        state *= gamma
        print("Reward: \(reward), State: \(state)")
    }
}

simulate_reward_decay()