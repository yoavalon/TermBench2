class FlightPlanner {
    var altitude: Int
    var velocity: Int
    var targetAltitude: Int
    var currentStep: Int

    init(altitude: Int, velocity: Int, targetAltitude: Int) {
        self.altitude = altitude
        self.velocity = velocity
        self.targetAltitude = targetAltitude
        self.currentStep = 0
    }

    func calculateStep() throws {
        if altitude < targetAltitude {
            altitude += velocity
            currentStep += 1
        } else {
            throw NSError(domain: "StopIteration", code: 1, userInfo: nil)
        }
    }

    func getStatus() -> (Int, Int) {
        return (altitude, currentStep)
    }
}

class BoundaryChecker {
    var maxAltitude: Int
    var minAltitude: Int

    init(maxAltitude: Int, minAltitude: Int) {
        self.maxAltitude = maxAltitude
        self.minAltitude = minAltitude
    }

    func checkBounds(altitude: Int) throws {
        if altitude > maxAltitude || altitude < minAltitude {
            throw NSError(domain: "ValueError", code: 1, userInfo: nil)
        }
    }
}

func main() {
    let initialAltitude = 1000
    let velocity = 200
    let targetAltitude = 3000
    let maxAltitude = 5000
    let minAltitude = 500
    let planner = FlightPlanner(altitude: initialAltitude, velocity: velocity, targetAltitude: targetAltitude)
    let checker = BoundaryChecker(maxAltitude: maxAltitude, minAltitude: minAltitude)

    do {
        while true {
            try planner.calculateStep()
            let (currentAltitude, stepCount) = planner.getStatus()
            try checker.checkBounds(altitude: currentAltitude)
            print("Step: \(stepCount), Altitude: \(currentAltitude)")
        }
    } catch {
        print("Termination: \(error.localizedDescription)")
    }
}

main()