func calculateAltitudeSequence(initialAltitude: Int, increment: Int, steps: Int) -> [Int] {
    var sequence = [Int]()
    for i in 0..<steps {
        sequence.append(initialAltitude + i * increment)
    }
    return sequence
}

func findOptimalCruiseAltitude(altitudes: [Int], maxFuelConsumption: Int) -> Int {
    let optimalAltitude = altitudes.max(by: { $0 > $1 && $0 <= maxFuelConsumption }) ?? altitudes.first!
    return optimalAltitude
}

func main() {
    let initial = 10000
    let increment = 1000
    let steps = 10
    let maxFuel = 15000
    let altitudes = calculateAltitudeSequence(initialAltitude: initial, increment: increment, steps: steps)
    let optimalAltitude = findOptimalCruiseAltitude(altitudes: altitudes, maxFuelConsumption: maxFuel)
    print(optimalAltitude)
}

main()