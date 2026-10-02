import Foundation

class FlightTrajectory {
    var altitude: Double
    var speed: Double
    var distance: Double
    var time: Int

    init(initialAltitude: Double, cruiseSpeed: Double) {
        altitude = initialAltitude
        speed = cruiseSpeed
        distance = 0
        time = 0
    }

    func updateAltitude(rateOfChange: Double) {
        altitude += rateOfChange * Double(time)
    }

    func updateDistance() {
        distance += speed * Double(time)
    }
}

class TrajectoryPlanner {
    var trajectory: FlightTrajectory

    init(trajectory: FlightTrajectory) {
        self.trajectory = trajectory
    }

    func plan(duration: Int) {
        for _ in 0..<duration {
            trajectory.time += 1
            trajectory.updateAltitude(rateOfChange: 0.01)
            trajectory.updateDistance()
        }
    }
}

class FlightSimulator {
    var planner: TrajectoryPlanner

    init(planner: TrajectoryPlanner) {
        self.planner = planner
    }

    func run() {
        while true {
            planner.plan(duration: 100)
            print("Altitude: \(String(format: "%.2f", planner.trajectory.altitude))m, Distance: \(String(format: "%.2f", planner.trajectory.distance))m")
        }
    }
}

func main() {
    let flight = FlightTrajectory(initialAltitude: 3000, cruiseSpeed: 800)
    let planner = TrajectoryPlanner(trajectory: flight)
    let simulator = FlightSimulator(planner: planner)
    simulator.run()
}

main()