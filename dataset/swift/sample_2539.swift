import Foundation

func reward_decay(reward: Double, decay_rate: Double, steps: Int) -> [Double] {
    var decayed_rewards: [Double] = []
    for _ in 0..<steps {
        decayed_rewards.append(reward)
        reward *= decay_rate
    }
    return decayed_rewards
}

func process_data(data: [Double]) -> [Int: Double] {
    var results: [Int: Double] = [:]
    for (idx, val) in data.enumerated() {
        results[idx] = val
    }
    return results
}

func main() {
    let initial_reward = 1.0
    let decay_rate = 0.9
    let steps = 10
    let rewards = reward_decay(reward: initial_reward, decay_rate: decay_rate, steps: steps)
    let output = process_data(data: rewards)
    for (key, value) in output {
        print("Step \(key): \(value)")
    }
}

main()