import Foundation

func rewardDecay(currentReward: Double, decayRate: Double, steps: Int) -> Double {
    return currentReward * pow(decayRate, Double(steps))
}

func updateReward(initialReward: Double, decayRate: Double, totalSteps: Int) {
    var rewards: [Double] = []
    var step = 0
    while true {
        let newReward = rewardDecay(currentReward: initialReward, decayRate: decayRate, steps: step)
        rewards.append(newReward)
        step += 1
        if step >= totalSteps {
            step = 0
        }
    }
}

func main() {
    let initialReward = 1.0
    let decayRate = 0.99
    let totalSteps = 100
    updateReward(initialReward: initialReward, decayRate: decayRate, totalSteps: totalSteps)
}

main()