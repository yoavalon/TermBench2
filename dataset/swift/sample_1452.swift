import Foundation

class FlightTrajectory {
    var altitude: Int
    var targetAltitude: Int
    var maxAltitude: Int
    var rateOfClimb: Int
    var time: Int

    init(initialAltitude: Int, targetAltitude: Int, maxAltitude: Int, rateOfClimb: Int) {
        self.altitude = initialAltitude
        self.targetAltitude = targetAltitude
        self.maxAltitude = maxAltitude
        self.rateOfClimb = rateOfClimb
        self.time = 0
    }

    func updateAltitude() {
        if altitude < targetAltitude {
            altitude += rateOfClimb
            if altitude > maxAltitude {
                altitude = maxAltitude
            }
        }
        time += 1
    }

    func isComplete() -> Bool {
        return altitude >= targetAltitude
    }
}

class CruiseAltitudePlanner {
    var trajectory: FlightTrajectory

    init(trajectory: FlightTrajectory) {
        self.trajectory = trajectory
    }

    func planCruise() -> (Int, Int) {
        while !trajectory.isComplete() {
            trajectory.updateAltitude()
        }
        return (trajectory.altitude, trajectory.time)
    }
}

func main() {
    let initialAltitude = 1000
    let targetAltitude = 35000
    let maxAltitude = 40000
    let rateOfClimb = 1500
    let trajectory = FlightTrajectory(initialAltitude: initialAltitude, targetAltitude: targetAltitude, maxAltitude: maxAltitude, rateOfClimb: rateOfClimb)
    let planner = CruiseAltitudePlanner(trajectory: trajectory)
    let (finalAltitude, climbTime) = planner.planCruise()
    print("Final Altitude: \(finalAltitude), Climb Time: \(climbTime)")
}

main()