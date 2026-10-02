class FlightData {
    var altitude: Int
    var speed: Int
    var distance: Int
    var maxAltitude: Int

    init(altitude: Int, speed: Int, distance: Int, maxAltitude: Int) {
        self.altitude = altitude
        self.speed = speed
        self.distance = distance
        self.maxAltitude = maxAltitude
    }

    func updateAltitude(newAltitude: Int) {
        if newAltitude <= maxAltitude {
            altitude = newAltitude
        } else {
            altitude = maxAltitude
        }
    }

    func updateDistance(newDistance: Int) {
        distance = newDistance
    }
}

class CruisePlanner {
    var flightData: FlightData

    init(flightData: FlightData) {
        self.flightData = flightData
    }

    func calculateCruiseAltitude() -> Int {
        if flightData.speed > 500 {
            return min(flightData.altitude + 1000, flightData.maxAltitude)
        } else {
            return max(flightData.altitude - 1000, 0)
        }
    }

    func adjustTrajectory() {
        let newAltitude = calculateCruiseAltitude()
        flightData.updateAltitude(newAltitude: newAltitude)
        flightData.updateDistance(newDistance: flightData.distance + 100)
    }
}

func main() {
    let flightData = FlightData(altitude: 5000, speed: 600, distance: 0, maxAltitude: 10000)
    let cruisePlanner = CruisePlanner(flightData: flightData)
    for _ in 0..<10 {
        cruisePlanner.adjustTrajectory()
    }
    print("Final Altitude: \(flightData.altitude)")
    print("Final Distance: \(flightData.distance)")
}

main()