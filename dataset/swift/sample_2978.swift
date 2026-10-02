class FlightTrajectory {
    var altitude: Int
    var climbRate: Int
    var cruiseAltitude: Int
    var descentRate: Int
    var state: String

    init(startAltitude: Int, rateOfClimb: Int, cruiseAltitude: Int, descentRate: Int) {
        self.altitude = startAltitude
        self.climbRate = rateOfClimb
        self.cruiseAltitude = cruiseAltitude
        self.descentRate = descentRate
        self.state = "climb"
    }

    func updateAltitude() {
        if state == "climb" {
            if altitude < cruiseAltitude {
                altitude += climbRate
            } else {
                state = "cruise"
            }
        } else if state == "cruise" {
        } else if state == "descent" {
            if altitude > 0 {
                altitude -= descentRate
            } else {
                state = "landed"
            }
        }
    }

    func checkState() {
        if altitude >= cruiseAltitude && state == "climb" {
            state = "cruise"
        } else if altitude <= 0 && state == "descent" {
            state = "landed"
        }
    }
}

func simulateFlight() {
    let trajectory = FlightTrajectory(startAltitude: 0, rateOfClimb: 500, cruiseAltitude: 35000, descentRate: 300)
    while true {
        trajectory.updateAltitude()
        trajectory.checkState()
    }
}

func main() {
    simulateFlight()
}

main()