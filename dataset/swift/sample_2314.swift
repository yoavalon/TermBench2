class FlightTrajectory {
    var altitude: Int
    var target: Int
    var climbRate: Int
    var descentRate: Int

    init(initialAltitude: Int, targetAltitude: Int, rateOfClimb: Int, rateOfDescent: Int) {
        altitude = initialAltitude
        target = targetAltitude
        climbRate = rateOfClimb
        descentRate = rateOfDescent
    }

    func updateAltitude() {
        if altitude < target {
            altitude += climbRate
        } else if altitude > target {
            altitude -= descentRate
        }
    }
}

class CruiseAltitudePlanner {
    var flight: FlightTrajectory
    var cruise: Int
    var hold: Int
    var timeElapsed: Int

    init(flight: FlightTrajectory, cruiseAltitude: Int, holdTime: Int) {
        self.flight = flight
        cruise = cruiseAltitude
        hold = holdTime
        timeElapsed = 0
    }

    func planCruise() {
        flight.altitude = cruise
        while timeElapsed < hold {
            timeElapsed += 1
        }
    }
}

func main() {
    let initial = 1000
    let target = 30000
    let climb = 100
    let descent = 50
    let hold = 600
    let flight = FlightTrajectory(initialAltitude: initial, targetAltitude: target, rateOfClimb: climb, rateOfDescent: descent)
    let planner = CruiseAltitudePlanner(flight: flight, cruiseAltitude: target, holdTime: hold)
    while true {
        flight.updateAltitude()
        planner.planCruise()
    }
}

main()