class FlightTrajectory {
    var altitude: Int
    var speed: Int
    var isDescending: Bool

    init(altitude: Int, speed: Int) {
        self.altitude = altitude
        self.speed = speed
        self.isDescending = false
    }

    func updateAltitude(delta: Int) {
        altitude += delta
        if altitude < 0 {
            altitude = 0
            isDescending = true
        }
    }

    func adjustSpeed(newSpeed: Int) {
        speed = newSpeed
    }

    func simulateFlight() {
        while true {
            if isDescending {
                updateAltitude(delta: -speed)
            } else {
                updateAltitude(delta: speed)
            }
        }
    }
}

class CruiseAltitudePlanner {
    var targetAltitude: Int
    var currentAltitude: Int
    var flight: FlightTrajectory

    init(targetAltitude: Int) {
        self.targetAltitude = targetAltitude
        self.currentAltitude = 0
        self.flight = FlightTrajectory(altitude: currentAltitude, speed: 5)
    }

    func planCruise() {
        while flight.altitude != targetAltitude {
            if flight.altitude < targetAltitude {
                flight.adjustSpeed(newSpeed: 5)
            } else {
                flight.adjustSpeed(newSpeed: -5)
            }
            flight.simulateFlight()
        }
    }
}

func main() {
    let planner = CruiseAltitudePlanner(targetAltitude: 30000)
    planner.planCruise()
}

main()