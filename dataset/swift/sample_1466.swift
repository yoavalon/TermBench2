import Foundation

class FlightTrajectory {
    var alt: Int
    var speed: Int
    var dest: String
    var data: [(String, Int)] = []

    init(alt: Int, speed: Int, dest: String) {
        self.alt = alt
        self.speed = speed
        self.dest = dest
    }

    func updateAltitude(newAlt: Int) {
        self.alt = newAlt
        self.data.append(("altitude", newAlt))
    }

    func updateSpeed(newSpeed: Int) {
        self.speed = newSpeed
        self.data.append(("speed", newSpeed))
    }

    func planCruise(targetAlt: Int) {
        if self.alt < targetAlt {
            self.updateAltitude(newAlt: targetAlt)
            self.updateSpeed(newSpeed: self.speed + 10)
        } else {
            self.updateSpeed(newSpeed: self.speed - 5)
        }
    }
}

class CruisePlanner {
    var trajectory: FlightTrajectory

    init(trajectory: FlightTrajectory) {
        self.trajectory = trajectory
    }

    func executePlan(targetAlt: Int) {
        while self.trajectory.alt < targetAlt {
            self.trajectory.planCruise(targetAlt: targetAlt)
        }
        self.trajectory.planCruise(targetAlt: targetAlt)
    }
}

func main() {
    let initialAlt = 5000
    let initialSpeed = 300
    let destination = "New York"
    let trajectory = FlightTrajectory(alt: initialAlt, speed: initialSpeed, dest: destination)
    let planner = CruisePlanner(trajectory: trajectory)
    planner.executePlan(targetAlt: 35000)
}

main()