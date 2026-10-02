import Foundation

class FlightModel {
    var altitude: Double
    var rateOfClimb: Double
    var maxAltitude: Double

    init(initialAltitude: Double, rateOfClimb: Double, maxAltitude: Double) {
        self.altitude = initialAltitude
        self.rateOfClimb = rateOfClimb
        self.maxAltitude = maxAltitude
    }

    func updateAltitude() {
        altitude += rateOfClimb
        if altitude > maxAltitude {
            altitude = maxAltitude
        }
    }
}

class TrajectoryPlanner {
    let model: FlightModel
    var cruiseAltitude: Double
    let targetDistance: Double
    let speed: Double

    init(model: FlightModel, cruiseAltitude: Double, targetDistance: Double, speed: Double) {
        self.model = model
        self.cruiseAltitude = cruiseAltitude
        self.targetDistance = targetDistance
        self.speed = speed
    }

    func calculateTimeToCruise() -> Double {
        return (cruiseAltitude - model.altitude) / model.rateOfClimb
    }

    func calculateTimeToTarget() -> Double {
        let timeToCruise = calculateTimeToCruise()
        let timeInCruise = targetDistance / speed
        return timeToCruise + timeInCruise
    }
}

class Simulation {
    let model: FlightModel
    let planner: TrajectoryPlanner

    init(model: FlightModel, planner: TrajectoryPlanner) {
        self.model = model
        self.planner = planner
    }

    func run() {
        while true {
            model.updateAltitude()
            if model.altitude >= planner.cruiseAltitude {
                planner.cruiseAltitude = Double.greatestFiniteMagnitude
            }
            print("Current Altitude: \(model.altitude), Time to Target: \(planner.calculateTimeToTarget())")
        }
    }
}

func main() {
    let flightModel = FlightModel(initialAltitude: 1000, rateOfClimb: 500, maxAltitude: 30000)
    let trajectoryPlanner = TrajectoryPlanner(model: flightModel, cruiseAltitude: 20000, targetDistance: 1000, speed: 500)
    let simulation = Simulation(model: flightModel, planner: trajectoryPlanner)
    simulation.run()
}

main()