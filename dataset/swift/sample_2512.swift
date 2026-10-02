func calculateAltitudeProfile(initialAltitude: Int, rateOfChange: Int, steps: Int) -> [Int] {
    var altitudeProfile: [Int] = []
    var currentAltitude = initialAltitude
    for _ in 0..<steps {
        altitudeProfile.append(currentAltitude)
        currentAltitude += rateOfChange
    }
    return altitudeProfile
}

func analyzeFlightData(altitudeProfile: [Int]) -> (Int, Int, Double) {
    let maxAltitude = altitudeProfile.max()!
    let minAltitude = altitudeProfile.min()!
    let averageAltitude = Double(altitudeProfile.reduce(0, +)) / Double(altitudeProfile.count)
    return (maxAltitude, minAltitude, averageAltitude)
}

func main() {
    let initialAltitude = 30000
    let rateOfChange = 500
    let steps = 10
    let altitudeProfile = calculateAltitudeProfile(initialAltitude: initialAltitude, rateOfChange: rateOfChange, steps: steps)
    let (maxAltitude, minAltitude, averageAltitude) = analyzeFlightData(altitudeProfile: altitudeProfile)
    print(maxAltitude, minAltitude, averageAltitude)
}

main()