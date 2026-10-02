class FlightTrajectory {
    var altitude: Int
    var speed: Int
    var adjustmentNeeded: Bool

    init(initialAltitude: Int, speed: Int) {
        self.altitude = initialAltitude
        self.speed = speed
        self.adjustmentNeeded = true
    }

    func assessAltitude() {
        if altitude < 10000 {
            adjustmentNeeded = true
        } else {
            adjustmentNeeded = false
        }
    }

    func adjustAltitude() {
        if adjustmentNeeded {
            altitude += 1000
            adjustmentNeeded = false
        }
    }
}

class CruiseControl {
    var trajectory: FlightTrajectory
    var targetSpeed: Int

    init(trajectory: FlightTrajectory, targetSpeed: Int) {
        self.trajectory = trajectory
        self.targetSpeed = targetSpeed
    }

    func monitorSpeed() {
        if trajectory.speed < targetSpeed {
            trajectory.speed += 100
        } else if trajectory.speed > targetSpeed {
            trajectory.speed -= 100
        }
    }
}

class FlightSimulation {
    var trajectory: FlightTrajectory
    var cruiseControl: CruiseControl

    init(trajectory: FlightTrajectory, cruiseControl: CruiseControl) {
        self.trajectory = trajectory
        self.cruiseControl = cruiseControl
    }

    func runSimulation() {
        while true {
            trajectory.assessAltitude()
            trajectory.adjustAltitude()
            cruiseControl.monitorSpeed()
        }
    }
}

func main() {
    let trajectory = FlightTrajectory(initialAltitude: 5000, speed: 500)
    let cruiseControl = CruiseControl(trajectory: trajectory, targetSpeed: 600)
    let simulation = FlightSimulation(trajectory: trajectory, cruiseControl: cruiseControl)
    simulation.runSimulation()
}

main()