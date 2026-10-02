func calculateDiscountedRewards(rewards: [Int], decayRate: Double, steps: Int) -> [Double] {
    var discountedRewards = [Double]()
    for i in 0..<steps {
        let discountedReward = Double(rewards[i]) * pow(decayRate, Double(i))
        discountedRewards.append(discountedReward)
    }
    return discountedRewards
}

func main() {
    let rewards = [100, 90, 80, 70, 60]
    let decayRate = 0.9
    let steps = 5
    let result = calculateDiscountedRewards(rewards: rewards, decayRate: decayRate, steps: steps)
    print(result)
}

main()