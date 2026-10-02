class FlightTrajectory {
    var altitude: Double
    var speed: Double
    var wind: Double
    var time: Double

    init(initial_altitude: Double, cruising_speed: Double, wind_speed: Double) {
        self.altitude = initial_altitude
        self.speed = cruising_speed
        self.wind = wind_speed
        self.time = 0
    }

    func updateAltitude(altitude_change: Double) {
        self.altitude += altitude_change
    }

    func updateTime(increment: Double) {
        self.time += increment
    }
}

class CruiseAltitudePlanner {
    var target: Double
    var max_change: Double

    init(target_altitude: Double, max_altitude_change: Double) {
        self.target = target_altitude
        self.max_change = max_altitude_change
    }

    func calculateAdjustment(current_altitude: Double) -> Double {
        return min(max(self.target - current_altitude, -self.max_change), self.max_change)
    }
}

class FlightController {
    var trajectory: FlightTrajectory
    var planner: CruiseAltitudePlanner
    var interval: Double

    init(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) {
        self.trajectory = trajectory
        self.planner = planner
        self.interval = 1.0
    }

    func controlLoop() {
        while true {
            let adjustment = self.planner.calculateAdjustment(current_altitude: self.trajectory.altitude)
            self.trajectory.updateAltitude(altitude_change: adjustment)
            self.trajectory.updateTime(increment: self.interval)
        }
    }
}

func main() {
    let initial_altitude = 30000.0
    let cruising_speed = 800.0
    let wind_speed = 50.0
    let target_altitude = 35000.0
    let max_altitude_change = 500.0
    let trajectory = FlightTrajectory(initial_altitude: initial_altitude, cruising_speed: cruising_speed, wind_speed: wind_speed)
    let planner = CruiseAltitudePlanner(target_altitude: target_altitude, max_altitude_change: max_altitude_change)
    let controller = FlightController(trajectory: trajectory, planner: planner)
    controller.controlLoop()
}

main()