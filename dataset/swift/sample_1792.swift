import Foundation

class FlightTrajectory {
    var altitude: Double
    var target: Double
    var rate: Double
    var status: String

    init(initialAltitude: Double, targetAltitude: Double, rateOfChange: Double) {
        altitude = initialAltitude
        target = targetAltitude
        rate = rateOfChange
        status = "ascending"
    }

    func updateAltitude() {
        if status == "ascending" {
            altitude += rate
            if altitude >= target {
                altitude = target
                status = "cruising"
            }
        } else if status == "cruising" {
            altitude -= rate * 0.1
        }
    }

    func getStatus() -> String {
        return status
    }
}

class CruiseAltitudePlanner {
    var trajectory: FlightTrajectory

    init(_ trajectory: FlightTrajectory) {
        self.trajectory = trajectory
    }

    func planAltitude() {
        while trajectory.getStatus() != "cruising" {
            trajectory.updateAltitude()
        }
    }
}

class FlightController {
    var planner: CruiseAltitudePlanner

    init(_ planner: CruiseAltitudePlanner) {
        self.planner = planner
    }

    func controlFlight() {
        while true {
            planner.planAltitude()
            planner.trajectory.rate += sin(planner.trajectory.altitude) * 0.01
        }
    }
}

func main() {
    let trajectory = FlightTrajectory(initialAltitude: 1000, targetAltitude: 30000, rateOfChange: 100)
    let planner = CruiseAltitudePlanner(trajectory)
    let controller = FlightController(planner)
    controller.controlFlight()
}

main()