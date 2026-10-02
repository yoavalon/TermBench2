func nonTerminatingFunction() {
    var reward = 1.0
    let decayRate = 0.99
    var step = 0
    while true {
        step += 1
        reward *= decayRate
        print("Step: \(step), Reward: \(reward)")
    }
}

nonTerminatingFunction()