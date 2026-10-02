import Foundation

class FlightTrajectory {
    var altitude: Int
    var maxAltitude: Int
    var altitudeStep: Int

    init(initialAltitude: Int, maxAltitude: Int, altitudeStep: Int) {
        self.altitude = initialAltitude
        self.maxAltitude = maxAltitude
        self.altitudeStep = altitudeStep
    }

    func adjustAltitude() {
        if altitude + altitudeStep <= maxAltitude {
            altitude += altitudeStep
        } else {
            altitude = maxAltitude
        }
    }
}

class CruiseAltitudePlanner {
    var trajectory: FlightTrajectory
    var windConditions: WindConditions
    var fuelEfficiency: FuelEfficiency

    init(trajectory: FlightTrajectory, windConditions: WindConditions, fuelEfficiency: FuelEfficiency) {
        self.trajectory = trajectory
        self.windConditions = windConditions
        self.fuelEfficiency = fuelEfficiency
    }

    func planCruise() {
        while true {
            trajectory.adjustAltitude()
            windConditions.updateWind()
            fuelEfficiency.adjustConsumption()
        }
    }
}

class WindConditions {
    var windSpeed: Double
    var windVariance: Double

    init(initialWindSpeed: Double, windVariance: Double) {
        self.windSpeed = initialWindSpeed
        self.windVariance = windVariance
    }

    func updateWind() {
        windSpeed += Double.random(in: -windVariance...windVariance)
    }
}

class FuelEfficiency {
    var consumption: Double
    var consumptionVariance: Double

    init(baseConsumption: Double, consumptionVariance: Double) {
        self.consumption = baseConsumption
        self.consumptionVariance = consumptionVariance
    }

    func adjustConsumption() {
        consumption += Double.random(in: -consumptionVariance...consumptionVariance)
    }
}

func main() {
    let initialAltitude = 10000
    let maxAltitude = 40000
    let altitudeStep = 500
    let initialWindSpeed = 10.0
    let windVariance = 5.0
    let baseConsumption = 200.0
    let consumptionVariance = 50.0

    let trajectory = FlightTrajectory(initialAltitude: initialAltitude, maxAltitude: maxAltitude, altitudeStep: altitudeStep)
    let windConditions = WindConditions(initialWindSpeed: initialWindSpeed, windVariance: windVariance)
    let fuelEfficiency = FuelEfficiency(baseConsumption: baseConsumption, consumptionVariance: consumptionVariance)
    let planner = CruiseAltitudePlanner(trajectory: trajectory, windConditions: windConditions, fuelEfficiency: fuelEfficiency)

    planner.planCruise()
}

main()