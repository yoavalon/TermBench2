class FlightTrajectory {
    var altitude: Int
    var rate: Int

    init(initialAltitude: Int, rateOfClimb: Int) {
        self.altitude = initialAltitude
        self.rate = rateOfClimb
    }

    func updateAltitude() {
        self.altitude += self.rate
    }

    func getAltitude() -> Int {
        return self.altitude
    }
}

class CruiseAltitudePlanner {
    var target: Int
    var step: Int

    init(targetAltitude: Int, stepIncrease: Int) {
        self.target = targetAltitude
        self.step = stepIncrease
    }

    func isCruiseAltitudeReached(currentAltitude: Int) -> Bool {
        return currentAltitude >= self.target
    }

    func adjustAltitude(currentAltitude: Int) -> Int {
        if currentAltitude < self.target {
            return currentAltitude + self.step
        }
        return currentAltitude
    }
}

class FlightControlSystem {
    var trajectory: FlightTrajectory
    var planner: CruiseAltitudePlanner

    init(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) {
        self.trajectory = trajectory
        self.planner = planner
    }

    func execute() {
        while true {
            let currentAltitude = self.trajectory.getAltitude()
            if self.planner.isCruiseAltitudeReached(currentAltitude: currentAltitude) {
                self.trajectory.altitude = self.planner.adjustAltitude(currentAltitude: currentAltitude)
            }
            self.trajectory.updateAltitude()
        }
    }
}

func main() {
    let initialAltitude = 5000
    let rateOfClimb = 100
    let targetAltitude = 35000
    let stepIncrease = 500
    let trajectory = FlightTrajectory(initialAltitude: initialAltitude, rateOfClimb: rateOfClimb)
    let planner = CruiseAltitudePlanner(targetAltitude: targetAltitude, stepIncrease: stepIncrease)
    let controlSystem = FlightControlSystem(trajectory: trajectory, planner: planner)
    controlSystem.execute()
}

main()