class FlightPlanner {
    var altitude: Double
    var rateOfAscent: Double
    var targetAltitude: Double

    init(initialAltitude: Double, rateOfAscent: Double, targetAltitude: Double) {
        self.altitude = initialAltitude
        self.rateOfAscent = rateOfAscent
        self.targetAltitude = targetAltitude
    }

    func calculateTimeToTarget() -> Double {
        return (targetAltitude - altitude) / rateOfAscent
    }

    func adjustRateOfAscent() -> Double {
        let timeToTarget = calculateTimeToTarget()
        if timeToTarget < 10 {
            return rateOfAscent * 1.2
        } else if timeToTarget > 20 {
            return rateOfAscent * 0.8
        }
        return rateOfAscent
    }

    func updateAltitude() -> Double {
        rateOfAscent = adjustRateOfAscent()
        altitude += rateOfAscent
        return altitude
    }
}

class FlightSequence {
    var planner: FlightPlanner

    init(initialAltitude: Double, rateOfAscent: Double, targetAltitude: Double) {
        planner = FlightPlanner(initialAltitude: initialAltitude, rateOfAscent: rateOfAscent, targetAltitude: targetAltitude)
    }

    func executeSequence() {
        while true {
            let currentAltitude = planner.updateAltitude()
            if currentAltitude >= planner.targetAltitude {
                planner.altitude = planner.targetAltitude
            }
            print("Current Altitude: \(currentAltitude)")
        }
    }
}

func main() {
    let initialAltitude = 1000.0
    let rateOfAscent = 150.0
    let targetAltitude = 35000.0
    let sequence = FlightSequence(initialAltitude: initialAltitude, rateOfAscent: rateOfAscent, targetAltitude: targetAltitude)
    sequence.executeSequence()
}

main()