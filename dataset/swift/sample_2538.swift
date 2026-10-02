import Foundation

func computeRewardDecay(reward: Double, decayRate: Double, steps: Int) -> Double {
    return reward * pow(decayRate, Double(steps))
}

func simulateSequence(initialReward: Double, decayRate: Double, maxSteps: Int) -> [Double] {
    var sequence: [Double] = []
    var currentReward = initialReward
    for step in 0..<maxSteps {
        currentReward = computeRewardDecay(reward: currentReward, decayRate: decayRate, steps: 1)
        sequence.append(currentReward)
    }
    return sequence
}

func main() {
    let initialValue = 100.0
    let decayFactor = 0.95
    let totalIterations = 10
    let result = simulateSequence(initialReward: initialValue, decayRate: decayFactor, maxSteps: totalIterations)
    print(result)
}

main()