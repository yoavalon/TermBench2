func sequenceRewardDecay(steps: Int, decayRate: Double) -> [Double] {
    var rewards: [Double] = []
    var reward = 1.0
    for _ in 0..<steps {
        rewards.append(reward)
        reward *= decayRate
    }
    return rewards
}

let steps = 10
let decayRate = 0.9
let result = sequenceRewardDecay(steps: steps, decayRate: decayRate)
print(result)