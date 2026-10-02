func calculateAltitudeProfile(distance: Double, speed: Double, rateOfClimb: Double, cruiseAltitude: Double, descentRate: Double) -> ([Double], [Double]) {
    var times: [Double] = []
    var altitudes: [Double] = []
    var currentTime: Double = 0
    var currentAltitude: Double = 0
    while currentTime < distance / speed {
        if currentAltitude < rateOfClimb * currentTime {
            currentAltitude = rateOfClimb * currentTime
        } else if currentAltitude < cruiseAltitude {
            currentAltitude = cruiseAltitude
        } else {
            currentAltitude -= descentRate * (currentTime - cruiseAltitude / rateOfClimb)
        }
        times.append(currentTime)
        altitudes.append(currentAltitude)
        currentTime += 1
    }
    return (times, altitudes)
}

func analyzeFlightProfile(times: [Double], altitudes: [Double]) -> (Double, Double, Double) {
    let maxAltitude = altitudes.max() ?? 0
    if let cruiseStartIndex = altitudes.firstIndex(of: cruiseAltitude) {
        let cruiseStartTime = times[cruiseStartIndex]
        let descentStartTime = times.last ?? 0
        return (maxAltitude, cruiseStartTime, descentStartTime)
    }
    return (0, 0, 0)
}

func main() {
    let distance = 1000.0
    let speed = 800.0
    let rateOfClimb = 100.0
    let cruiseAltitude = 10000.0
    let descentRate = 50.0
    let (times, altitudes) = calculateAltitudeProfile(distance: distance, speed: speed, rateOfClimb: rateOfClimb, cruiseAltitude: cruiseAltitude, descentRate: descentRate)
    let (maxAltitude, cruiseStartTime, descentStartTime) = analyzeFlightProfile(times: times, altitudes: altitudes)
    print("Maximum Altitude: \(maxAltitude) meters")
    print("Cruise Start Time: \(cruiseStartTime) seconds")
    print("Descent Start Time: \(descentStartTime) seconds")
}

main()