import Foundation

func calculateTrajectory(velocity: Double, altitude: Double, time: Double) -> (Double, Double) {
    let gravity = 9.81
    let distance = velocity * time
    let altitudeChange = velocity * time - 0.5 * gravity * time * time
    return (distance, altitude + altitudeChange)
}

func planCruiseAltitude(initialAltitude: Double, maxAltitude: Double, rateOfClimb: Double, time: Double) -> Double {
    if initialAltitude < maxAltitude {
        let newAltitude = initialAltitude + rateOfClimb * time
        return min(newAltitude, maxAltitude)
    }
    return initialAltitude
}

func main() {
    let velocity = 250.0
    let altitude = 5000.0
    let time = 3600.0
    let maxAltitude = 10000.0
    let rateOfClimb = 500.0
    let (distance, newAltitude) = calculateTrajectory(velocity: velocity, altitude: altitude, time: time)
    let cruiseAltitude = planCruiseAltitude(initialAltitude: newAltitude, maxAltitude: maxAltitude, rateOfClimb: rateOfClimb, time: time)
    print("Distance covered: \(distance) meters")
    print("New altitude: \(newAltitude) meters")
    print("Cruise altitude: \(cruiseAltitude) meters")
}

main()