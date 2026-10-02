class FlightTrajectory {
    var altitude: Int
    var target: Int
    var rate: Int

    init(initialAltitude: Int, targetAltitude: Int, rateOfClimb: Int) {
        self.altitude = initialAltitude
        self.target = targetAltitude
        self.rate = rateOfClimb
    }

    func updateAltitude() -> Int {
        if altitude < target {
            altitude += rate
        }
        return altitude
    }
}

class CruiseAltitudePlanner {
    var trajectory: FlightTrajectory
    var cruise: Int

    init(trajectory: FlightTrajectory, cruiseAltitude: Int) {
        self.trajectory = trajectory
        self.cruise = cruiseAltitude
    }

    func planCruise() -> Int {
        while trajectory.altitude < cruise {
            trajectory.updateAltitude()
        }
        return cruise
    }
}

class FlightControl {
    var planner: CruiseAltitudePlanner

    init(planner: CruiseAltitudePlanner) {
        self.planner = planner
    }

    func executeFlight() {
        while true {
            let cruiseAltitude = planner.planCruise()
            print("Cruise altitude reached: \(cruiseAltitude) meters")
        }
    }
}

func main() {
    let initialAltitude = 1000
    let targetAltitude = 8000
    let rateOfClimb = 150
    let cruiseAltitude = 10000
    let trajectory = FlightTrajectory(initialAltitude: initialAltitude, targetAltitude: targetAltitude, rateOfClimb: rateOfClimb)
    let planner = CruiseAltitudePlanner(trajectory: trajectory, cruiseAltitude: cruiseAltitude)
    let flightControl = FlightControl(planner: planner)
    flightControl.executeFlight()
}

main()