func computeRewardDecay(initialReward: Double, decayRate: Double, timeSteps: Int) -> Double {
    var reward = initialReward
    for _ in 0..<timeSteps {
        reward *= decayRate
    }
    return reward
}

func simulateDataMutation(initialData: [Double], decayRate: Double, steps: Int) -> [Double] {
    var mutatedData: [Double] = []
    for dataPoint in initialData {
        let reward = computeRewardDecay(initialReward: dataPoint, decayRate: decayRate, timeSteps: steps)
        mutatedData.append(reward)
    }
    return mutatedData
}

func main() {
    let data = [100.0, 200.0, 300.0, 400.0, 500.0]
    let rate = 0.95
    let steps = 10
    let result = simulateDataMutation(initialData: data, decayRate: rate, steps: steps)
    print(result)
}

main()