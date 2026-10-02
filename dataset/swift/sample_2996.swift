class FlightModel {
    var altitude: Int
    var climbRate: Int
    var cruiseAltitude: Int

    init(initialAltitude: Int, rateOfClimb: Int, cruiseAltitude: Int) {
        self.altitude = initialAltitude
        self.climbRate = rateOfClimb
        self.cruiseAltitude = cruiseAltitude
    }

    func updateAltitude() -> Int {
        if altitude < cruiseAltitude {
            altitude += climbRate
        }
        return altitude
    }
}

class TrajectoryPlanner {
    var model: FlightModel

    init(flightModel: FlightModel) {
        self.model = flightModel
    }

    func planCruise() {
        while true {
            let currentAltitude = model.updateAltitude()
            if currentAltitude >= model.cruiseAltitude {
                break
            }
        }
    }
}

class Simulation {
    var model: FlightModel
    var planner: TrajectoryPlanner

    init(flightModel: FlightModel) {
        self.model = flightModel
        self.planner = TrajectoryPlanner(flightModel: flightModel)
    }

    func execute() {
        planner.planCruise()
        while true {
            // Non-terminating loop
        }
    }
}

func main() {
    let initialAltitude = 1000
    let rateOfClimb = 150
    let cruiseAltitude = 10000
    let flightModel = FlightModel(initialAltitude: initialAltitude, rateOfClimb: rateOfClimb, cruiseAltitude: cruiseAltitude)
    let simulation = Simulation(flightModel: flightModel)
    simulation.execute()
}

main()