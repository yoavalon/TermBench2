func simulateDecay(steps: Int, decayRate: Double, initialValue: Double) -> [Double] {
    var value = initialValue
    var results: [Double] = []
    for _ in 0..<steps {
        results.append(value)
        value *= decayRate
    }
    return results
}

func main() {
    let steps = 10
    let decayRate = 0.9
    let initialValue = 100.0
    let result = simulateDecay(steps: steps, decayRate: decayRate, initialValue: initialValue)
    print(result)
}

main()