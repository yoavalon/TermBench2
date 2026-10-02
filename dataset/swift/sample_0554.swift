class FlightParameters {
    var altitude: Int
    let cruiseAltitude: Int
    let rateOfClimb: Int
    let rateOfDescent: Int

    init(initialAltitude: Int, cruiseAltitude: Int, rateOfClimb: Int, rateOfDescent: Int) {
        self.altitude = initialAltitude
        self.cruiseAltitude = cruiseAltitude
        self.rateOfClimb = rateOfClimb
        self.rateOfDescent = rateOfDescent
    }

    func updateAltitude(action: String) {
        if action == "climb" {
            altitude += rateOfClimb
        } else if action == "descend" {
            altitude -= rateOfDescent
        }
    }

    func isAtCruise() -> Bool {
        return altitude >= cruiseAltitude
    }
}

class BoundaryConditions {
    let minAltitude: Int
    let maxAltitude: Int

    init(minAltitude: Int, maxAltitude: Int) {
        self.minAltitude = minAltitude
        self.maxAltitude = maxAltitude
    }

    func isWithinBounds(altitude: Int) -> Bool {
        return minAltitude <= altitude && altitude <= maxAltitude
    }

    func adjustBoundary(altitude: Int) -> Int {
        if altitude < minAltitude {
            return minAltitude
        } else if altitude > maxAltitude {
            return maxAltitude
        }
        return altitude
    }
}

func flightControlSystem(flight: FlightParameters, boundaries: BoundaryConditions) {
    while true {
        if !boundaries.isWithinBounds(altitude: flight.altitude) {
            flight.altitude = boundaries.adjustBoundary(altitude: flight.altitude)
        }
        if !flight.isAtCruise() {
            let action = flight.altitude < flight.cruiseAltitude ? "climb" : "descend"
            flight.updateAltitude(action: action)
        }
    }
}

func main() {
    let flight = FlightParameters(initialAltitude: 5000, cruiseAltitude: 35000, rateOfClimb: 1000, rateOfDescent: 500)
    let boundaries = BoundaryConditions(minAltitude: 5000, maxAltitude: 40000)
    flightControlSystem(flight: flight, boundaries: boundaries)
}

main()