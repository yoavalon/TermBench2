class FlightTrajectory {
    var altitude: Int
    var maxAltitude: Int
    var speed: Int

    init(initialAltitude: Int, maxAltitude: Int, speed: Int) {
        self.altitude = initialAltitude
        self.maxAltitude = maxAltitude
        self.speed = speed
    }

    func updateAltitude(time: Int) {
        self.altitude += self.speed * time
        if self.altitude > self.maxAltitude {
            self.altitude = self.maxAltitude
        }
    }
}

class CruiseAltitudePlanner {
    var trajectory: FlightTrajectory
    var targetAltitude: Int

    init(trajectory: FlightTrajectory) {
        self.trajectory = trajectory
        self.targetAltitude = trajectory.maxAltitude
    }

    func adjustAltitude(currentTime: Int) {
        if self.trajectory.altitude < self.targetAltitude {
            let timeToAdjust = (self.targetAltitude - self.trajectory.altitude) / self.trajectory.speed
            if currentTime >= timeToAdjust {
                self.trajectory.updateAltitude(time: timeToAdjust)
            }
        }
    }
}

class TerminationChecker {
    var trajectory: FlightTrajectory
    var targetAltitude: Int

    init(trajectory: FlightTrajectory, targetAltitude: Int) {
        self.trajectory = trajectory
        self.targetAltitude = targetAltitude
    }

    func check() -> Bool {
        return self.trajectory.altitude >= self.targetAltitude
    }
}

func main() {
    let initialAltitude = 1000
    let maxAltitude = 30000
    let speed = 1500
    let trajectory = FlightTrajectory(initialAltitude: initialAltitude, maxAltitude: maxAltitude, speed: speed)
    let planner = CruiseAltitudePlanner(trajectory: trajectory)
    let checker = TerminationChecker(trajectory: trajectory, targetAltitude: maxAltitude)
    var currentTime = 0
    let timeStep = 10
    while !checker.check() {
        planner.adjustAltitude(currentTime: currentTime)
        currentTime += timeStep
    }
    print("Cruise altitude reached.")
}

main()