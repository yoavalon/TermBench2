class FlightPath {
    var altitude: Int
    var targetAltitude: Int
    var rateOfClimb: Int

    init(startAltitude: Int, targetAltitude: Int, rateOfClimb: Int) {
        self.altitude = startAltitude
        self.targetAltitude = targetAltitude
        self.rateOfClimb = rateOfClimb
    }

    func climb() {
        altitude += rateOfClimb
        if altitude > targetAltitude {
            altitude = targetAltitude
        }
    }

    func getStatus() -> (Int, Int) {
        return (altitude, targetAltitude)
    }
}

class CruiseAltitude {
    var altitude: Int
    var maxSpeed: Int
    var windSpeed: Int

    init(altitude: Int, maxSpeed: Int, windSpeed: Int) {
        self.altitude = altitude
        self.maxSpeed = maxSpeed
        self.windSpeed = windSpeed
    }

    func adjustSpeed() {
        maxSpeed = maxSpeed - windSpeed / 2
    }

    func getSpeed() -> Int {
        return maxSpeed
    }
}

func main() {
    let flight = FlightPath(startAltitude: 1000, targetAltitude: 35000, rateOfClimb: 100)
    let cruise = CruiseAltitude(altitude: 35000, maxSpeed: 800, windSpeed: 20)
    while true {
        flight.climb()
        cruise.adjustSpeed()
        let (currentAlt, targetAlt) = flight.getStatus()
        let currentSpeed = cruise.getSpeed()
        if currentAlt == targetAlt {
            print("Reached target altitude: \(currentAlt)")
            print("Cruise speed adjusted to: \(currentSpeed)")
        } else {
            print("Current altitude: \(currentAlt), Target altitude: \(targetAlt)")
            print("Current speed: \(currentSpeed)")
        }
    }
}

main()