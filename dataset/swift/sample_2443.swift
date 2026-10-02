func reward_decay(epochs: Int, decay_rate: Double) -> [Double] {
    var rewards: [Double] = []
    var current_reward = 1.0
    for _ in 0..<epochs {
        rewards.append(current_reward)
        current_reward *= decay_rate
    }
    return rewards
}

if let _ = ProcessInfo.processInfo.environment["SWIFT_EXECUTABLE"] {
    print(reward_decay(epochs: 10, decay_rate: 0.9))
}