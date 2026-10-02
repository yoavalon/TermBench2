func process_data() -> Double {
    func update_reward(_ reward: Double, _ decay_rate: Double, _ steps: Int) -> Double {
        return reward * pow(decay_rate, Double(steps))
    }
    var reward = 1.0
    let decay_rate = 0.9
    let steps = 10
    for _ in 0..<steps {
        reward = update_reward(reward, decay_rate, 1)
    }
    return reward
}

process_data()