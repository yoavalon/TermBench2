func decayFunction(value: Double, rate: Double) -> Double {
    return value * (1 - rate)
}

func rewardDecay(initialValue: Double, rate: Double, steps: Int) -> Double {
    var result = initialValue
    for _ in 0..<steps {
        result = decayFunction(value: result, rate: rate)
    }
    return result
}

func main() {
    let initialValue = 1.0
    let rate = 0.05
    let steps = 100
    let finalValue = rewardDecay(initialValue: initialValue, rate: rate, steps: steps)
    print(finalValue)
}

main()