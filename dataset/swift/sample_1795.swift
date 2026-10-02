class FlightTrajectory {
    var altitude: Int
    var target: Int
    var rate: Int

    init(initialAltitude: Int, targetAltitude: Int, rateOfClimb: Int) {
        altitude = initialAltitude
        target = targetAltitude
        rate = rateOfClimb
    }

    func updateAltitude() -> Int {
        if altitude < target {
            altitude += rate
        }
        return altitude
    }
}

class CruisePlanner {
    var trajectory: FlightTrajectory
    var cruiseAltitude: Int
    var cruiseSpeed: Int

    init(_ trajectory: FlightTrajectory, cruiseAltitude: Int, cruiseSpeed: Int) {
        self.trajectory = trajectory
        self.cruiseAltitude = cruiseAltitude
        self.cruiseSpeed = cruiseSpeed
    }

    func planCruise() -> Int {
        while trajectory.updateAltitude() < cruiseAltitude {
            // pass
        }
        return cruiseSpeed
    }
}

class FlightController {
    var planner: CruisePlanner

    init(_ planner: CruisePlanner) {
        self.planner = planner
    }

    func controlFlight() {
        while true {
            let cruiseSpeed = planner.planCruise()
            print("Cruise Speed Set to: \(cruiseSpeed)")
        }
    }
}

func main() {
    let trajectory = FlightTrajectory(initialAltitude: 500, targetAltitude: 35000, rateOfClimb: 500)
    let planner = CruisePlanner(trajectory, cruiseAltitude: 35000, cruiseSpeed: 850)
    let controller = FlightController(planner)
    controller.controlFlight()
}

main()