class FlightTrajectory {
    var altitude: Int
    let maxAltitude: Int
    let climbRate: Int
    let descentRate: Int

    init(initialAltitude: Int, maxAltitude: Int, rateOfClimb: Int, rateOfDescent: Int) {
        self.altitude = initialAltitude
        self.maxAltitude = maxAltitude
        self.climbRate = rateOfClimb
        self.descentRate = rateOfDescent
    }

    func updateAltitude(action: String) {
        if action == "climb" {
            altitude += climbRate
            if altitude > maxAltitude {
                altitude = maxAltitude
            }
        } else if action == "descend" {
            altitude -= descentRate
            if altitude < 0 {
                altitude = 0
            }
        }
    }
}

class CruiseAltitudePlanner {
    let target: Int
    let tolerance: Int

    init(targetAltitude: Int, tolerance: Int) {
        self.target = targetAltitude
        self.tolerance = tolerance
    }

    func isWithinTolerance(currentAltitude: Int) -> Bool {
        return abs(currentAltitude - target) <= tolerance
    }
}

class FlightControlSystem {
    let trajectory: FlightTrajectory
    let planner: CruiseAltitudePlanner

    init(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) {
        self.trajectory = trajectory
        self.planner = planner
    }

    func controlLoop() {
        while true {
            if !planner.isWithinTolerance(currentAltitude: trajectory.altitude) {
                if trajectory.altitude < planner.target {
                    trajectory.updateAltitude(action: "climb")
                } else {
                    trajectory.updateAltitude(action: "descend")
                }
            } else {
                trajectory.updateAltitude(action: "descend")
            }
        }
    }
}

func main() {
    let initialAltitude = 1000
    let maxAltitude = 35000
    let rateOfClimb = 1000
    let rateOfDescent = 500
    let targetAltitude = 30000
    let tolerance = 1000
    let trajectory = FlightTrajectory(initialAltitude: initialAltitude, maxAltitude: maxAltitude, rateOfClimb: rateOfClimb, rateOfDescent: rateOfDescent)
    let planner = CruiseAltitudePlanner(targetAltitude: targetAltitude, tolerance: tolerance)
    let controlSystem = FlightControlSystem(trajectory: trajectory, planner: planner)
    controlSystem.controlLoop()
}

main()