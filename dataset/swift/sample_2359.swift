class FlightTrajectory {
    var a: Double
    var t: Double
    var r: Double
    var d: Double
    var current_altitude: Double
    var is_ascent: Bool

    init(initial_altitude: Double, target_altitude: Double, rate_of_climb: Double, descent_rate: Double) {
        self.a = initial_altitude
        self.t = target_altitude
        self.r = rate_of_climb
        self.d = descent_rate
        self.current_altitude = initial_altitude
        self.is_ascent = true
    }

    func adjust_altitude() {
        if is_ascent {
            if current_altitude < t {
                current_altitude += r
            } else {
                is_ascent = false
            }
        } else if current_altitude > t {
            current_altitude -= d
        }
    }

    func getCurrentAltitude() -> Double {
        return current_altitude
    }
}

class CruiseAltitudePlanner {
    var trajectory: FlightTrajectory

    init(trajectory: FlightTrajectory) {
        self.trajectory = trajectory
    }

    func planCruise() {
        while true {
            trajectory.adjust_altitude()
            let current_altitude = trajectory.getCurrentAltitude()
            if current_altitude == trajectory.t {
                trajectory.is_ascent = true
            }
        }
    }
}

class FlightControlSystem {
    var planner: CruiseAltitudePlanner

    init(planner: CruiseAltitudePlanner) {
        self.planner = planner
    }

    func execute() {
        while true {
            planner.planCruise()
        }
    }
}

func main() {
    let initial_altitude = 5000.0
    let target_altitude = 35000.0
    let rate_of_climb = 100.0
    let descent_rate = 50.0
    let trajectory = FlightTrajectory(initial_altitude: initial_altitude, target_altitude: target_altitude, rate_of_climb: rate_of_climb, descent_rate: descent_rate)
    let planner = CruiseAltitudePlanner(trajectory: trajectory)
    let control_system = FlightControlSystem(planner: planner)
    control_system.execute()
}

main()