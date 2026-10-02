import Foundation

class FlightTrajectory {
    var altitude: Double
    var rate_of_climb: Double
    var cruise_altitude: Double
    var descent_rate: Double
    var status: String

    init(initial_altitude: Double, rate_of_climb: Double, cruise_altitude: Double, descent_rate: Double) {
        self.altitude = initial_altitude
        self.rate_of_climb = rate_of_climb
        self.cruise_altitude = cruise_altitude
        self.descent_rate = descent_rate
        self.status = "climbing"
    }

    func update_altitude() {
        if status == "climbing" {
            if altitude + rate_of_climb < cruise_altitude {
                altitude += rate_of_climb
            } else {
                altitude = cruise_altitude
                status = "cruising"
            }
        } else if status == "cruising" {
            // No change
        } else if status == "descending" {
            if altitude - descent_rate > 0 {
                altitude -= descent_rate
            } else {
                altitude = 0
                status = "landed"
            }
        }
    }

    func is_landed() -> Bool {
        return status == "landed"
    }
}

class FlightPlanner {
    var trajectory: FlightTrajectory

    init(trajectory: FlightTrajectory) {
        self.trajectory = trajectory
    }

    func plan_flight() {
        while !trajectory.is_landed() {
            trajectory.update_altitude()
            log_status()
        }
    }

    func log_status() {
        print("Altitude: \(trajectory.altitude), Status: \(trajectory.status)")
    }
}

func main() {
    let initial_altitude = 0.0
    let rate_of_climb = 1000.0
    let cruise_altitude = 30000.0
    let descent_rate = 500.0
    let trajectory = FlightTrajectory(initial_altitude: initial_altitude, rate_of_climb: rate_of_climb, cruise_altitude: cruise_altitude, descent_rate: descent_rate)
    let planner = FlightPlanner(trajectory: trajectory)
    planner.plan_flight()
}

main()