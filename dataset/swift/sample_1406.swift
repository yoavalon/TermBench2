class FlightPlanner {
    var currentAltitude: Int
    var targetAltitude: Int
    var altitudeStep: Int
    var descentRate: Int

    init(initialAltitude: Int, targetAltitude: Int, altitudeStep: Int, descentRate: Int) {
        self.currentAltitude = initialAltitude
        self.targetAltitude = targetAltitude
        self.altitudeStep = altitudeStep
        self.descentRate = descentRate
    }

    func adjustAltitude() {
        if currentAltitude > targetAltitude {
            currentAltitude -= altitudeStep
            if currentAltitude < targetAltitude {
                currentAltitude = targetAltitude
            }
        } else {
            currentAltitude += altitudeStep
            if currentAltitude > targetAltitude {
                currentAltitude = targetAltitude
            }
        }
    }

    func simulateFlight() -> Int {
        while currentAltitude != targetAltitude {
            adjustAltitude()
        }
        return currentAltitude
    }
}

class TrajectoryAnalyzer {
    var currentPosition: Int
    var targetPosition: Int
    var positionStep: Int
    var direction: Int

    init(initialPosition: Int, targetPosition: Int, positionStep: Int, direction: Int) {
        self.currentPosition = initialPosition
        self.targetPosition = targetPosition
        self.positionStep = positionStep
        self.direction = direction
    }

    func updatePosition() {
        if currentPosition < targetPosition {
            currentPosition += positionStep
        } else if currentPosition > targetPosition {
            currentPosition -= positionStep
        }
    }

    func analyzeTrajectory() -> Int {
        while currentPosition != targetPosition {
            updatePosition()
        }
        return currentPosition
    }
}

func main() {
    let altitudePlanner = FlightPlanner(initialAltitude: 30000, targetAltitude: 35000, altitudeStep: 1000, descentRate: 500)
    let trajectoryAnalyzer = TrajectoryAnalyzer(initialPosition: 0, targetPosition: 1000, positionStep: 100, direction: 1)
    let finalAltitude = altitudePlanner.simulateFlight()
    let finalPosition = trajectoryAnalyzer.analyzeTrajectory()
    print("Final Altitude: \(finalAltitude)")
    print("Final Position: \(finalPosition)")
}

main()