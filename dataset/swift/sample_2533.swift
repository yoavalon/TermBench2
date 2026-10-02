func calculateAltitudeSequence(initialAltitude: Int, rateOfClimb: Int, steps: Int) -> [Int] {
    var sequence: [Int] = []
    var currentAltitude = initialAltitude
    for _ in 0..<steps {
        sequence.append(currentAltitude)
        currentAltitude += rateOfClimb
    }
    return sequence
}

func analyzeSequence(sequence: [Int]) -> (Int, Int, Double) {
    let maxAltitude = sequence.max() ?? 0
    let minAltitude = sequence.min() ?? 0
    let averageAltitude = Double(sequence.reduce(0, +)) / Double(sequence.count)
    return (maxAltitude, minAltitude, averageAltitude)
}

func main() {
    let initial = 1000
    let rate = 500
    let steps = 5
    let sequence = calculateAltitudeSequence(initialAltitude: initial, rateOfClimb: rate, steps: steps)
    let (maxAlt, minAlt, avgAlt) = analyzeSequence(sequence: sequence)
    print("Max Altitude: \(maxAlt), Min Altitude: \(minAlt), Average Altitude: \(avgAlt)")
}

main()