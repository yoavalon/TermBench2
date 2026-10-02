class FlightTrajectory {
    var altitude: Int
    var target: Int
    var rate: Int
    var status: String

    init(startAltitude: Int, targetAltitude: Int, rateOfClimb: Int) {
        altitude = startAltitude
        target = targetAltitude
        rate = rateOfClimb
        status = "ascending"
    }

    func updateAltitude() -> Int {
        if status == "ascending" {
            altitude += rate
            if altitude >= target {
                status = "cruising"
                altitude = target
            }
        }
        return altitude
    }

    func isCruising() -> Bool {
        return status == "cruising"
    }
}

func planCruiseAltitude(trajectory: FlightTrajectory, maxIterations: Int) -> Int {
    var iteration = 0
    while iteration < maxIterations && !trajectory.isCruising() {
        trajectory.updateAltitude()
        iteration += 1
    }
    return trajectory.altitude
}

func main() {
    let start = 1000
    let target = 35000
    let rate = 500
    let maxIter = 1000
    let trajectory = FlightTrajectory(startAltitude: start, targetAltitude: target, rateOfClimb: rate)
    let finalAltitude = planCruiseAltitude(trajectory: trajectory, maxIterations: maxIter)
    print("Final Cruise Altitude:", finalAltitude)
}

main()