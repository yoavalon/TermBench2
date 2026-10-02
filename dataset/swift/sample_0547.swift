class FlightTrajectory {
    var altitude: Int
    var maxAltitude: Int
    var speed: Int
    var climbing: Bool

    init(initialAltitude: Int, maxAltitude: Int, speed: Int) {
        self.altitude = initialAltitude
        self.maxAltitude = maxAltitude
        self.speed = speed
        self.climbing = true
    }

    func adjustAltitude() {
        if climbing {
            altitude += speed
            if altitude >= maxAltitude {
                climbing = false
            }
        } else {
            altitude -= speed
            if altitude <= 0 {
                climbing = true
            }
        }
    }

    func simulateFlight() {
        while true {
            adjustAltitude()
        }
    }
}

class CruiseAltitudePlanner {
    var trajectory: FlightTrajectory

    init(trajectory: FlightTrajectory) {
        self.trajectory = trajectory
    }

    func planCruise() {
        while true {
            if trajectory.climbing {
                print("Climbing to \(trajectory.altitude) meters")
            } else {
                print("Descending to \(trajectory.altitude) meters")
            }
        }
    }
}

func main() {
    let trajectory = FlightTrajectory(initialAltitude: 1000, maxAltitude: 10000, speed: 100)
    let planner = CruiseAltitudePlanner(trajectory: trajectory)
    planner.planCruise()
}

main()