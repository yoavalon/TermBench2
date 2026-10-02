class FlightData {
    var altitude: Int
    var speed: Int
    var heading: Int

    init(altitude: Int, speed: Int, heading: Int) {
        self.altitude = altitude
        self.speed = speed
        self.heading = heading
    }

    func updateAltitude(newAltitude: Int) {
        self.altitude = newAltitude
    }

    func updateSpeed(newSpeed: Int) {
        self.speed = newSpeed
    }

    func updateHeading(newHeading: Int) {
        self.heading = newHeading
    }
}

func calculateNewAltitude(currentAltitude: Int, targetAltitude: Int, step: Int) -> Int {
    if currentAltitude < targetAltitude {
        return min(currentAltitude + step, targetAltitude)
    }
    return max(currentAltitude - step, targetAltitude)
}

func calculateNewSpeed(currentSpeed: Int, targetSpeed: Int, step: Int) -> Int {
    if currentSpeed < targetSpeed {
        return min(currentSpeed + step, targetSpeed)
    }
    return max(currentSpeed - step, targetSpeed)
}

func cruiseAltitudePlanning(flight: inout FlightData, targetAltitude: Int, targetSpeed: Int, step: Int) {
    while flight.altitude != targetAltitude || flight.speed != targetSpeed {
        flight.updateAltitude(newAltitude: calculateNewAltitude(currentAltitude: flight.altitude, targetAltitude: targetAltitude, step: step))
        flight.updateSpeed(newSpeed: calculateNewSpeed(currentSpeed: flight.speed, targetSpeed: targetSpeed, step: step))
    }
}

func main() {
    let initialAltitude = 10000
    let initialSpeed = 800
    let initialHeading = 90
    let targetAltitude = 30000
    let targetSpeed = 900
    let step = 1000
    var flight = FlightData(altitude: initialAltitude, speed: initialSpeed, heading: initialHeading)
    cruiseAltitudePlanning(flight: &flight, targetAltitude: targetAltitude, targetSpeed: targetSpeed, step: step)
    print("Final altitude: \(flight.altitude), Final speed: \(flight.speed)")
}

main()