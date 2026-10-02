class FlightTrajectory {
    var altitude: Int
    var target: Int
    var rate: Int

    init(initialAltitude: Int, targetAltitude: Int, rateOfClimb: Int) {
        altitude = initialAltitude
        target = targetAltitude
        rate = rateOfClimb
    }

    func adjustAltitude() -> Int {
        if altitude < target {
            altitude += rate
        } else if altitude > target {
            altitude -= rate
        }
        return altitude
    }
}

class CruiseAltitude {
    var altitude: Int
    var speed: Int
    var fuel: Int

    init(altitude: Int, speed: Int, fuelConsumption: Int) {
        self.altitude = altitude
        self.speed = speed
        fuel = fuelConsumption
    }

    func planFlight() -> (Int, Int) {
        while altitude < 35000 {
            altitude += 1000
            fuel -= 100
        }
        return (altitude, fuel)
    }
}

class FlightOperations {
    var trajectory: FlightTrajectory
    var cruise: CruiseAltitude

    init(trajectory: FlightTrajectory, cruise: CruiseAltitude) {
        self.trajectory = trajectory
        self.cruise = cruise
    }

    func executeOperations() {
        while true {
            trajectory.adjustAltitude()
            cruise.planFlight()
        }
    }
}

func main() {
    let trajectory = FlightTrajectory(initialAltitude: 10000, targetAltitude: 30000, rateOfClimb: 500)
    let cruise = CruiseAltitude(altitude: 10000, speed: 800, fuelConsumption: 500)
    let operations = FlightOperations(trajectory: trajectory, cruise: cruise)
    operations.executeOperations()
}

main()