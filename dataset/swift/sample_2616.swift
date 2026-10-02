class FlightTrajectory {
    var altitude: Int
    var target: Int
    var rate: Int

    init(startAltitude: Int, targetAltitude: Int, rate: Int) {
        self.altitude = startAltitude
        self.target = targetAltitude
        self.rate = rate
    }

    func updateAltitude() -> Int {
        if altitude < target {
            altitude += rate
            if altitude > target {
                altitude = target
            }
        }
        return altitude
    }

    func isAtTarget() -> Bool {
        return altitude == target
    }
}

class CruiseAltitudePlanner {
    var trajectory: FlightTrajectory
    var steps: Int

    init(trajectory: FlightTrajectory) {
        self.trajectory = trajectory
        self.steps = 0
    }

    func plan() {
        while !trajectory.isAtTarget() {
            let currentAltitude = trajectory.updateAltitude()
            steps += 1
            print("Step \(steps): Altitude = \(currentAltitude)")
        }
    }
}

func main() {
    let start = 1000
    let target = 35000
    let rate = 1500
    let trajectory = FlightTrajectory(startAltitude: start, targetAltitude: target, rate: rate)
    let planner = CruiseAltitudePlanner(trajectory: trajectory)
    planner.plan()
    print("Reached target altitude in \(planner.steps) steps.")
}

main()