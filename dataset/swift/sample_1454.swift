class FlightTrajectory {
    var currentAltitude: Int
    var targetAltitude: Int
    var rateOfClimb: Int
    var cruiseAltitude: Int?

    init(startAltitude: Int, targetAltitude: Int, rateOfClimb: Int) {
        self.currentAltitude = startAltitude
        self.targetAltitude = targetAltitude
        self.rateOfClimb = rateOfClimb
        self.cruiseAltitude = nil
    }

    func updateAltitude() {
        if currentAltitude < targetAltitude {
            currentAltitude += rateOfClimb
            if currentAltitude >= targetAltitude {
                currentAltitude = targetAltitude
                setCruiseAltitude()
            }
        }
    }

    func setCruiseAltitude() {
        cruiseAltitude = currentAltitude
    }

    func getCurrentAltitude() -> Int {
        return currentAltitude
    }

    func isAtTarget() -> Bool {
        return currentAltitude == targetAltitude
    }
}

class AltitudePlanner {
    var trajectory: FlightTrajectory
    var targetAltitude: Int

    init(trajectory: FlightTrajectory, targetAltitude: Int) {
        self.trajectory = trajectory
        self.targetAltitude = targetAltitude
    }

    func planCruiseAltitude() -> Int {
        while !trajectory.isAtTarget() {
            trajectory.updateAltitude()
        }
        return trajectory.getCurrentAltitude()
    }
}

func main() {
    let startAltitude = 1000
    let targetAltitude = 35000
    let rateOfClimb = 500
    let trajectory = FlightTrajectory(startAltitude: startAltitude, targetAltitude: targetAltitude, rateOfClimb: rateOfClimb)
    let planner = AltitudePlanner(trajectory: trajectory, targetAltitude: targetAltitude)
    let cruiseAltitude = planner.planCruiseAltitude()
    print("Cruise Altitude Set: \(cruiseAltitude) feet")
}

main()