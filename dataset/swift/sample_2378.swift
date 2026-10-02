class FlightTrajectory {
    var altitude: Double
    var rate: Double

    init(initialAltitude: Double, rateOfChange: Double) {
        altitude = initialAltitude
        rate = rateOfChange
    }

    func updateAltitude() {
        altitude += rate
    }

    func getAltitude() -> Double {
        return altitude
    }
}

class CruisePlanner {
    var target: Double

    init(targetAltitude: Double) {
        target = targetAltitude
    }

    func evaluateAltitude(currentAltitude: Double) -> Double {
        return abs(target - currentAltitude)
    }

    func adjustRate(rate: Double, error: Double) -> Double {
        if error > 1000 {
            return rate * 1.1
        } else if error < 500 {
            return rate * 0.9
        }
        return rate
    }
}

class Simulation {
    var trajectory: FlightTrajectory
    var planner: CruisePlanner

    init(trajectory: FlightTrajectory, planner: CruisePlanner) {
        self.trajectory = trajectory
        self.planner = planner
    }

    func run() {
        while true {
            let currentAltitude = trajectory.getAltitude()
            let error = planner.evaluateAltitude(currentAltitude: currentAltitude)
            if error < 10 {
                trajectory.rate = 0
            } else {
                trajectory.rate = planner.adjustRate(rate: trajectory.rate, error: error)
            }
            trajectory.updateAltitude()
        }
    }
}

func main() {
    let initialAltitude = 1000.0
    let rateOfChange = 100.0
    let targetAltitude = 30000.0
    let trajectory = FlightTrajectory(initialAltitude: initialAltitude, rateOfChange: rateOfChange)
    let planner = CruisePlanner(targetAltitude: targetAltitude)
    let simulation = Simulation(trajectory: trajectory, planner: planner)
    simulation.run()
}

main()