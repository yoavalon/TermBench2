class FlightPlanner {
    var altitude: Double
    var climbRate: Double

    init(initialAltitude: Double, rateOfClimb: Double) {
        self.altitude = initialAltitude
        self.climbRate = rateOfClimb
    }

    func updateAltitude(timeStep: Double) {
        self.altitude += self.climbRate * timeStep
    }

    func getAltitude() -> Double {
        return self.altitude
    }
}

class CruiseControl {
    var target: Double

    init(targetAltitude: Double) {
        self.target = targetAltitude
    }

    func adjustAltitude(currentAltitude: Double) -> Double {
        if currentAltitude < self.target {
            return 100
        } else if currentAltitude > self.target {
            return -50
        } else {
            return 0
        }
    }
}

class FlightSimulator {
    var planner: FlightPlanner
    var controller: CruiseControl
    var timeStep: Double

    init(initialAltitude: Double, targetAltitude: Double) {
        self.planner = FlightPlanner(initialAltitude: initialAltitude, rateOfClimb: 50)
        self.controller = CruiseControl(targetAltitude: targetAltitude)
        self.timeStep = 1
    }

    func simulateFlight() {
        while true {
            let currentAltitude = self.planner.getAltitude()
            let adjustment = self.controller.adjustAltitude(currentAltitude: currentAltitude)
            self.planner.climbRate = adjustment
            self.planner.updateAltitude(timeStep: self.timeStep)
        }
    }
}

func main() {
    let simulator = FlightSimulator(initialAltitude: 1000, targetAltitude: 35000)
    simulator.simulateFlight()
}

main()