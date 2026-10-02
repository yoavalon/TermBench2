class FlightTrajectory {
    var altitude: Double
    var speed: Double
    var time: Double

    init(initial_altitude: Double, cruise_speed: Double) {
        self.altitude = initial_altitude
        self.speed = cruise_speed
        self.time = 0.0
    }

    func updateAltitude(rateOfChange: Double) {
        self.altitude += rateOfChange
        self.time += 1.0
    }

    func getAltitude() -> Double {
        return self.altitude
    }
}

class CruiseAltitudePlanner {
    var target: Double
    var maxChange: Double

    init(targetAltitude: Double, maxRateOfChange: Double) {
        self.target = targetAltitude
        self.maxChange = maxRateOfChange
    }

    func calculateAdjustment(currentAltitude: Double) -> Double {
        let difference = self.target - currentAltitude
        let adjustment = min(abs(difference), self.maxChange)
        return difference > 0 ? adjustment : -adjustment
    }
}

class FlightController {
    var trajectory: FlightTrajectory
    var planner: CruiseAltitudePlanner

    init(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) {
        self.trajectory = trajectory
        self.planner = planner
    }

    func execute() {
        while true {
            let currentAltitude = self.trajectory.getAltitude()
            let adjustment = self.planner.calculateAdjustment(currentAltitude: currentAltitude)
            self.trajectory.updateAltitude(rateOfChange: adjustment)
        }
    }
}

func main() {
    let trajectory = FlightTrajectory(initial_altitude: 5000, cruise_speed: 900)
    let planner = CruiseAltitudePlanner(targetAltitude: 35000, maxRateOfChange: 1000)
    let controller = FlightController(trajectory: trajectory, planner: planner)
    controller.execute()
}

main()