class Flight {
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

func boundaryCheck(flight: Flight, minAlt: Int, maxAlt: Int) {
    if flight.altitude < minAlt {
        flight.updateAltitude(newAltitude: minAlt)
    } else if flight.altitude > maxAlt {
        flight.updateAltitude(newAltitude: maxAlt)
    }
}

func cruiseControl(flight: Flight, targetSpeed: Int) {
    if flight.speed < targetSpeed {
        flight.updateSpeed(newSpeed: flight.speed + 1)
    } else if flight.speed > targetSpeed {
        flight.updateSpeed(newSpeed: flight.speed - 1)
    }
}

func flightSimulation() {
    let flight = Flight(altitude: 10000, speed: 500, heading: 90)
    let minAltitude = 5000
    let maxAltitude = 30000
    let targetSpeed = 600
    while true {
        boundaryCheck(flight: flight, minAlt: minAltitude, maxAlt: maxAltitude)
        cruiseControl(flight: flight, targetSpeed: targetSpeed)
    }
}

func main() {
    flightSimulation()
}

main()