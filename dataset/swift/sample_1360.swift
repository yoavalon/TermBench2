import Foundation

func computeDecay(reward: Double, rate: Double, steps: Int) -> [Double] {
    var decayedRewards: [Double] = []
    for step in 0..<steps {
        let decayedReward = reward * pow(rate, Double(step))
        decayedRewards.append(decayedReward)
        if decayedReward < 0.01 {
            break
        }
    }
    return decayedRewards
}

func analyzeData(data: [Double]) -> (Double, Double) {
    let total = data.reduce(0, +)
    let average = data.count > 0 ? total / Double(data.count) : 0
    return (total, average)
}

func main() {
    let initialReward = 1.0
    let decayRate = 0.95
    let maxSteps = 1000
    let rewards = computeDecay(reward: initialReward, rate: decayRate, steps: maxSteps)
    let (total, average) = analyzeData(data: rewards)
    print("Total Reward: \(total), Average Reward: \(average)")
}

main()