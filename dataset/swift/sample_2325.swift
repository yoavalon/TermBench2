class FlightTrajectory {
    var altitude: Double
    var target: Double
    var climbRate: Double
    var descentRate: Double

    init(initialAltitude: Double, targetAltitude: Double, rateOfClimb: Double, rateOfDescent: Double) {
        altitude = initialAltitude
        target = targetAltitude
        climbRate = rateOfClimb
        descentRate = rateOfDescent
    }

    func adjustAltitude() -> Double {
        if altitude < target {
            altitude += climbRate
        } else if altitude > target {
            altitude -= descentRate
        }
        return altitude
    }

    func stabilizeAltitude() {
        while abs(altitude - target) > 0.1 {
            adjustAltitude()
        }
    }
}

class CruiseAltitudePlanner {
    var trajectory: FlightTrajectory

    init(trajectory: FlightTrajectory) {
        self.trajectory = trajectory
    }

    func plan() {
        while true {
            trajectory.stabilizeAltitude()
            print(String(format: "Current Altitude: %.2f", trajectory.altitude))
        }
    }
}

func main() {
    let initial = 5000.0
    let target = 35000.0
    let climb = 100.0
    let descent = 50.0
    let trajectory = FlightTrajectory(initialAltitude: initial, targetAltitude: target, rateOfClimb: climb, rateOfDescent: descent)
    let planner = CruiseAltitudePlanner(trajectory: trajectory)
    planner.plan()
}

main()