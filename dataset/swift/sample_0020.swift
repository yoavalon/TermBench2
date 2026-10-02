func simulate_decay(steps: Int) -> Double {
    var reward = 1.0
    let decay_rate = 0.99
    for _ in 0..<steps {
        reward *= decay_rate
    }
    return reward
}

if let command = CommandLine.arguments.first, command == "main" {
    let result = simulate_decay(steps: 1000)
    print(result)
}