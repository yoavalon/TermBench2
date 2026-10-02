class FlightTrajectory {
    var altitude: Int
    var target: Int
    var step: Int

    init(initialAltitude: Int, targetAltitude: Int, step: Int) {
        self.altitude = initialAltitude
        self.target = targetAltitude
        self.step = step
    }

    func adjustAltitude() -> Int {
        if altitude < target {
            altitude += step
        } else {
            altitude -= step
        }
        return altitude
    }
}

class CruiseAltitudePlanner {
    var trajectory: FlightTrajectory

    init(trajectory: FlightTrajectory) {
        self.trajectory = trajectory
    }

    func planAltitude() {
        while true {
            let newAltitude = trajectory.adjustAltitude()
            if abs(newAltitude - trajectory.target) < trajectory.step {
                break
            }
        }
    }
}

class Simulation {
    var planner: CruiseAltitudePlanner

    init(planner: CruiseAltitudePlanner) {
        self.planner = planner
    }

    func run() {
        while true {
            planner.planAltitude()
        }
    }
}

func main() {
    let initial = 10000
    let target = 30000
    let step = 1000
    let trajectory = FlightTrajectory(initialAltitude: initial, targetAltitude: target, step: step)
    let planner = CruiseAltitudePlanner(trajectory: trajectory)
    let simulation = Simulation(planner: planner)
    simulation.run()
}

main()