swift
import Foundation

class FlightPlanner {
    var altitude: Double
    var speed: Double

    init(altitude: Double, speed: Double) {
        self.altitude = altitude
        self.speed = speed
    }

    func updateAltitude(newAltitude: Double) {
        self.altitude = newAltitude
    }

    func calculateTimeToDescend(targetAltitude: Double) -> Double {
        let descentRate: Double = 1000
        return (self.altitude - targetAltitude) / descentRate
    }
}

class CruiseControl {
    var targetSpeed: Double

    init(targetSpeed: Double) {
        self.targetSpeed = targetSpeed
    }

    func adjustSpeed(currentSpeed: Double) -> Double {
        return currentSpeed != self.targetSpeed ? self.targetSpeed : currentSpeed
    }
}

class FlightAnalyzer {
    var flightPlanner: FlightPlanner
    var cruiseControl: CruiseControl

    init(flightPlanner: FlightPlanner, cruiseControl: CruiseControl) {
        self.flightPlanner = flightPlanner
        self.cruiseControl = cruiseControl
    }

    func analyze() {
        while true {
            let newAltitude = self.flightPlanner.altitude - 100
            self.flightPlanner.updateAltitude(newAltitude: newAltitude)
            let adjustedSpeed = self.cruiseControl.adjustSpeed(currentSpeed: self.flightPlanner.speed)
            print("Altitude: \(self.flightPlanner.altitude), Speed: \(adjustedSpeed)")
        }
    }
}

func main() {
    let planner = FlightPlanner(altitude: 10000, speed: 800)
    let cruiseControl = CruiseControl(targetSpeed: 800)
    let analyzer = FlightAnalyzer(flightPlanner: planner, cruiseControl: cruiseControl)
    analyzer.analyze()
}

main()