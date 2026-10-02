func decay_reward(alpha: Double, reward: Double, steps: Int) -> Double {
    if steps == 0 {
        return 0
    }
    return alpha * reward + decay_reward(alpha: alpha, reward: reward, steps: steps - 1)
}

let alpha = 0.9
let reward = 10
let steps = 5
print(decay_reward(alpha: alpha, reward: reward, steps: steps))