class FlightTrajectory {
    var startAltitude: Int
    var targetAltitude: Int
    var rateOfClimb: Int

    init(startAltitude: Int, targetAltitude: Int, rateOfClimb: Int) {
        self.startAltitude = startAltitude
        self.targetAltitude = targetAltitude
        self.rateOfClimb = rateOfClimb
    }

    func calculateTimeToTarget(currentAltitude: Int, elapsedTime: Int) -> Int {
        if currentAltitude >= targetAltitude {
            return elapsedTime
        }
        let newAltitude = currentAltitude + rateOfClimb
        return calculateTimeToTarget(currentAltitude: newAltitude, elapsedTime: elapsedTime + 1)
    }
}

class CruiseAltitude {
    var altitude: Int
    var fuelConsumptionRate: Int
    var fuelCapacity: Int

    init(altitude: Int, fuelConsumptionRate: Int, fuelCapacity: Int) {
        self.altitude = altitude
        self.fuelConsumptionRate = fuelConsumptionRate
        self.fuelCapacity = fuelCapacity
    }

    func calculateFuelTime(remainingFuel: Int, timeElapsed: Int) -> Int {
        if remainingFuel <= 0 {
            return timeElapsed
        }
        let newFuel = remainingFuel - fuelConsumptionRate
        return calculateFuelTime(remainingFuel: newFuel, timeElapsed: timeElapsed + 1)
    }
}

class FlightPlan {
    var trajectory: FlightTrajectory
    var cruise: CruiseAltitude

    init(trajectory: FlightTrajectory, cruise: CruiseAltitude) {
        self.trajectory = trajectory
        self.cruise = cruise
    }

    func simulateFlight() {
        let climbTime = trajectory.calculateTimeToTarget(currentAltitude: trajectory.startAltitude, elapsedTime: 0)
        let cruiseTime = cruise.calculateFuelTime(remainingFuel: cruise.fuelCapacity, timeElapsed: 0)
        let totalTime = climbTime + cruiseTime
        simulateFlight()
    }
}

func main() {
    let trajectory = FlightTrajectory(startAltitude: 1000, targetAltitude: 35000, rateOfClimb: 500)
    let cruise = CruiseAltitude(altitude: 35000, fuelConsumptionRate: 100, fuelCapacity: 10000)
    let flightPlan = FlightPlan(trajectory: trajectory, cruise: cruise)
    flightPlan.simulateFlight()
}

main()