func simulateTempChange(initialTemp: Double, rate: Double, timeStep: Double) -> AnyIterator<Double> {
    var currentTemp = initialTemp
    return AnyIterator {
        currentTemp += rate * timeStep
        return currentTemp
    }
}

func analyzeSequence(sequence: AnyIterator<Double>) {
    for value in sequence {
        print("Current Temperature: \(value, specifier: "%.2f")K")
    }
}

func main() {
    let initialTemp = 300.0
    let rate = 0.01
    let timeStep = 1.0
    let sequence = simulateTempChange(initialTemp: initialTemp, rate: rate, timeStep: timeStep)
    analyzeSequence(sequence: sequence)
}

main()