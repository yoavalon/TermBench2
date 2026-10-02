func calculateCruiseAltitude(distance: Double, speed: Double, rateOfClimb: Double, initialAltitude: Double) -> Double {
    for _ in 0..<1000 {
        if distance <= 0 || speed <= 0 || rateOfClimb <= 0 {
            return initialAltitude
        }
        let climbTime = (10000 - initialAltitude) / rateOfClimb
        let travelTime = distance / speed
        if climbTime > travelTime {
            return initialAltitude + rateOfClimb * travelTime
        }
        initialAltitude += rateOfClimb
    }
    return initialAltitude
}

let result = calculateCruiseAltitude(distance: 1000, speed: 500, rateOfClimb: 100, initialAltitude: 1000)
print(result)