import Foundation

func simulateRewardDecay(steps: Int, decayRate: Double) -> [Double] {
    var rewards = [Double.random(in: 0...1)]
    for _ in 1..<steps {
        rewards.append(rewards.last! * decayRate)
    }
    return rewards
}

func main() {
    let steps = 10
    let decayRate = 0.9
    let result = simulateRewardDecay(steps: steps, decayRate: decayRate)
    print(result)
}

main()