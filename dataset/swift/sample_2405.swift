func reward_decay(alpha: Double, gamma: Double, steps: Int) -> Double {
    var reward = 1.0
    for _ in 0..<steps {
        reward *= alpha * gamma
    }
    return reward
}

let alpha = 0.5
let gamma = 0.9
let steps = 10
let result = reward_decay(alpha: alpha, gamma: gamma, steps: steps)
print(result)