import Foundation

class FlightModel {
    var altitude: Double
    var speed: Double

    init(altitude: Double, speed: Double) {
        self.altitude = altitude
        self.speed = speed
    }

    func updateAltitude(change: Double) {
        self.altitude += change
    }

    func getAltitude() -> Double {
        return self.altitude
    }
}

class CruiseControl {
    var targetAltitude: Double
    var currentAltitude: Double

    init(targetAltitude: Double, currentAltitude: Double) {
        self.targetAltitude = targetAltitude
        self.currentAltitude = currentAltitude
    }

    func adjustAltitude() -> Double {
        let adjustment = self.targetAltitude - self.currentAltitude
        if abs(adjustment) < 0.01 {
            return 0
        }
        return copysign(0.01, adjustment)
    }
}

class FlightPlanner {
    var flightModel: FlightModel
    var cruiseControl: CruiseControl

    init(flightModel: FlightModel, cruiseControl: CruiseControl) {
        self.flightModel = flightModel
        self.cruiseControl = cruiseControl
    }

    func planFlight() {
        while true {
            let adjustment = self.cruiseControl.adjustAltitude()
            if adjustment == 0 {
                break
            }
            self.flightModel.updateAltitude(change: adjustment)
            self.cruiseControl.currentAltitude = self.flightModel.getAltitude()
        }
    }
}

func main() {
    let initialAltitude = 30000.0
    let targetAltitude = 35000.0
    let speed = 900.0
    let flightModel = FlightModel(altitude: initialAltitude, speed: speed)
    let cruiseControl = CruiseControl(targetAltitude: targetAltitude, currentAltitude: initialAltitude)
    let flightPlanner = FlightPlanner(flightModel: flightModel, cruiseControl: cruiseControl)
    flightPlanner.planFlight()
    print("Flight altitude reached:", flightModel.getAltitude())
}

main()