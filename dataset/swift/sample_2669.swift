swift
class FlightPlanner {
    var currentAltitude: Int
    var targetAltitude: Int
    var rateOfClimb: Int

    init(initialAltitude: Int, targetAltitude: Int, rateOfClimb: Int) {
        self.currentAltitude = initialAltitude
        self.targetAltitude = targetAltitude
        self.rateOfClimb = rateOfClimb
    }

    func calculateClimbSequence() -> [Int] {
        var sequence: [Int] = []
        while currentAltitude < targetAltitude {
            let nextAltitude = currentAltitude + rateOfClimb
            sequence.append(nextAltitude)
            currentAltitude = nextAltitude
        }
        return sequence
    }

    func planTrajectory() -> [Int] {
        let sequence = calculateClimbSequence()
        var trajectory: [Int] = Array(repeating: 0, count: sequence.count)
        for i in 0..<sequence.count {
            trajectory[i] = sequence[i]
        }
        return trajectory
    }
}

class CruiseAltitudeManager {
    var cruiseAltitude: Int
    var duration: Int

    init(cruiseAltitude: Int, duration: Int) {
        self.cruiseAltitude = cruiseAltitude
        self.duration = duration
    }

    func generateCruiseSequence() -> [Int] {
        return Array(repeating: cruiseAltitude, count: duration)
    }
}

func main() {
    let initialAltitude = 1000
    let targetAltitude = 35000
    let rateOfClimb = 1000
    let cruiseAltitude = 35000
    let duration = 100
    let flightPlanner = FlightPlanner(initialAltitude: initialAltitude, targetAltitude: targetAltitude, rateOfClimb: rateOfClimb)
    let climbSequence = flightPlanner.planTrajectory()
    let cruiseManager = CruiseAltitudeManager(cruiseAltitude: cruiseAltitude, duration: duration)
    let cruiseSequence = cruiseManager.generateCruiseSequence()
    let fullSequence = climbSequence + cruiseSequence
    for altitude in fullSequence {
        print(altitude)
    }
}

main()