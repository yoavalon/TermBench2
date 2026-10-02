class FlightTrajectory {
    var currentAltitude: Int
    var targetAltitude: Int
    var rateOfClimb: Int
    var rateOfDescent: Int

    init(initialAltitude: Int, targetAltitude: Int, rateOfClimb: Int, rateOfDescent: Int) {
        self.currentAltitude = initialAltitude
        self.targetAltitude = targetAltitude
        self.rateOfClimb = rateOfClimb
        self.rateOfDescent = rateOfDescent
    }

    func climb() {
        if currentAltitude < targetAltitude {
            currentAltitude += rateOfClimb
            if currentAltitude > targetAltitude {
                currentAltitude = targetAltitude
            }
        }
    }

    func descend() {
        if currentAltitude > targetAltitude {
            currentAltitude -= rateOfDescent
            if currentAltitude < targetAltitude {
                currentAltitude = targetAltitude
            }
        }
    }

    func adjustAltitude() {
        if currentAltitude < targetAltitude {
            climb()
        } else if currentAltitude > targetAltitude {
            descend()
        }
    }
}

class CruiseAltitudeManager {
    var trajectory: FlightTrajectory
    var cruiseAltitude: Int
    var altitudeChanges: [Int]

    init(trajectory: FlightTrajectory) {
        self.trajectory = trajectory
        self.cruiseAltitude = trajectory.targetAltitude
        self.altitudeChanges = []
    }

    func updateCruiseAltitude(newAltitude: Int) {
        cruiseAltitude = newAltitude
        trajectory.targetAltitude = newAltitude
    }

    func logAltitudeChange() {
        altitudeChanges.append(trajectory.currentAltitude)
    }

    func manageCruise() {
        trajectory.adjustAltitude()
        logAltitudeChange()
    }
}

class FlightSimulation {
    var trajectory: FlightTrajectory
    var cruiseManager: CruiseAltitudeManager

    init(initialAltitude: Int, targetAltitude: Int, rateOfClimb: Int, rateOfDescent: Int) {
        self.trajectory = FlightTrajectory(initialAltitude: initialAltitude, targetAltitude: targetAltitude, rateOfClimb: rateOfClimb, rateOfDescent: rateOfDescent)
        self.cruiseManager = CruiseAltitudeManager(trajectory: trajectory)
    }

    func simulateFlight() {
        while true {
            cruiseManager.manageCruise()
        }
    }
}

func main() {
    let flightSim = FlightSimulation(initialAltitude: 5000, targetAltitude: 35000, rateOfClimb: 500, rateOfDescent: 300)
    flightSim.simulateFlight()
}

main()