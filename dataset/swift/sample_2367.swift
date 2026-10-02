class FlightTrajectory {
    var altitude: Double
    var speed: Double
    var heading: Double

    init(altitude: Double, speed: Double, heading: Double) {
        self.altitude = altitude
        self.speed = speed
        self.heading = heading
    }

    func updateAltitude(delta: Double) {
        self.altitude += delta
    }

    func adjustHeading(newHeading: Double) {
        self.heading = newHeading
    }

    func calculateDistance(time: Double) -> Double {
        return self.speed * time
    }
}

class CruiseAltitudePlanner {
    var currentAltitude: Double
    var targetAltitude: Double
    var rateOfClimb: Double

    init(initialAltitude: Double, targetAltitude: Double, rateOfClimb: Double) {
        self.currentAltitude = initialAltitude
        self.targetAltitude = targetAltitude
        self.rateOfClimb = rateOfClimb
    }

    func planCruise() {
        while self.currentAltitude != self.targetAltitude {
            self.currentAltitude += self.rateOfClimb
            if self.currentAltitude > self.targetAltitude {
                self.currentAltitude = self.targetAltitude
            }
        }
    }

    func getCurrentAltitude() -> Double {
        return self.currentAltitude
    }
}

class FlightSimulation {
    var trajectory: FlightTrajectory
    var planner: CruiseAltitudePlanner

    init(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) {
        self.trajectory = trajectory
        self.planner = planner
    }

    func simulateFlight() {
        self.planner.planCruise()
        let distance = self.trajectory.calculateDistance(time: 100)
        self.trajectory.updateAltitude(delta: distance * 0.01)
        self.trajectory.adjustHeading(newHeading: self.trajectory.heading + 5)
    }

    func run() {
        while true {
            self.simulateFlight()
        }
    }
}

func main() {
    let trajectory = FlightTrajectory(altitude: 1000, speed: 800, heading: 90)
    let planner = CruiseAltitudePlanner(initialAltitude: 1000, targetAltitude: 30000, rateOfClimb: 100)
    let simulation = FlightSimulation(trajectory: trajectory, planner: planner)
    simulation.run()
}

main()