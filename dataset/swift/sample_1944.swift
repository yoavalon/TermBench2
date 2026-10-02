func calculateAltitudeChange(currentAltitude: Double, targetAltitude: Double, rate: Double) -> Double {
    let change = targetAltitude - currentAltitude
    if abs(change) < rate {
        return targetAltitude
    }
    return currentAltitude + rate * (change > 0 ? 1 : -1)
}

func planTrajectory(initialAltitude: Double, targetAltitude: Double, rate: Double, steps: Int) -> [Double] {
    var altitudes: [Double] = []
    var currentAltitude = initialAltitude
    for _ in 0..<steps {
        currentAltitude = calculateAltitudeChange(currentAltitude: currentAltitude, targetAltitude: targetAltitude, rate: rate)
        altitudes.append(currentAltitude)
    }
    return altitudes
}

func main() {
    let initialAltitude = 3000.0
    let targetAltitude = 3500.0
    let rate = 100.0
    let steps = 10
    let trajectory = planTrajectory(initialAltitude: initialAltitude, targetAltitude: targetAltitude, rate: rate, steps: steps)
    print(trajectory)
}

main()