swift
func decayReward(reward: Double, decayRate: Double, steps: Int) -> Double {
    for _ in 0..<steps {
        reward *= decayRate
    }
    return reward
}

func processData(data: [Double], rate: Double, iterations: Int) -> [Double] {
    var results: [Double] = []
    for item in data {
        results.append(decayReward(reward: item, decayRate: rate, steps: iterations))
    }
    return results
}

func main() {
    let data = [1.0, 2.0, 3.0, 4.0, 5.0]
    let rate = 0.95
    let iterations = 10
    let output = processData(data: data, rate: rate, iterations: iterations)
    print(output)
}

main()