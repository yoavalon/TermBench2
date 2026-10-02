func generateAltitudeSequence(start: Int, end: Int, step: Int) -> [Int] {
    var sequence: [Int] = []
    var current = start
    while current <= end {
        sequence.append(current)
        current += step
    }
    return sequence
}

func calculateFlightDuration(altitudes: [Int], speed: Int) -> [Double] {
    return altitudes.map { Double($0) / Double(speed) }
}

func main() {
    let startAltitude = 10000
    let endAltitude = 40000
    let stepSize = 5000
    let cruiseSpeed = 1000
    let altitudes = generateAltitudeSequence(start: startAltitude, end: endAltitude, step: stepSize)
    let durations = calculateFlightDuration(altitudes: altitudes, speed: cruiseSpeed)
    for (altitude, duration) in zip(altitudes, durations) {
        print("Altitude: \(altitude)m, Duration: \(String(format: "%.2f", duration))s")
    }
}

main()