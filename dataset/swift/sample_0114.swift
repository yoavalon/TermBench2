import Foundation

func calculateRewardDecay(initialReward: Double, decayRate: Double, step: Int) -> Double {
    return initialReward * pow(decayRate, Double(step))
}

func simulateEpisode(initialReward: Double, decayRate: Double, maxSteps: Int) -> Double {
    var totalReward = 0.0
    var step = 0
    while step < maxSteps {
        let reward = calculateRewardDecay(initialReward: initialReward, decayRate: decayRate, step: step)
        totalReward += reward
        step += 1
    }
    return totalReward
}

func main() {
    let initialReward = 1.0
    let decayRate = 0.9
    let maxSteps = 10
    let result = simulateEpisode(initialReward: initialReward, decayRate: decayRate, maxSteps: maxSteps)
    print(result)
}

main()