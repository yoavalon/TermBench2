class FlightData {
    var altitude: Double
    var velocity: Double
    var windSpeed: Double

    init(altitude: Double, velocity: Double, windSpeed: Double) {
        self.altitude = altitude
        self.velocity = velocity
        self.windSpeed = windSpeed
    }

    func updateAltitude(adjustment: Double) {
        self.altitude += adjustment
    }

    func calculateDrag() -> Double {
        return 0.5 * self.velocity * self.windSpeed
    }
}

class TrajectoryPlanner {
    var flightData: FlightData

    init(flightData: FlightData) {
        self.flightData = flightData
    }

    func optimizeAltitude(targetDrag: Double) {
        var adjustment = 0.1
        while true {
            let drag = self.flightData.calculateDrag()
            if abs(drag - targetDrag) < 0.01 {
                break
            }
            if drag > targetDrag {
                adjustment = -adjustment
            }
            self.flightData.updateAltitude(adjustment: adjustment)
        }
    }

    func planCruise() {
        let targetDrag = 150.0
        self.optimizeAltitude(targetDrag: targetDrag)
    }
}

class FlightControl {
    var flightData: FlightData
    var planner: TrajectoryPlanner

    init() {
        self.flightData = FlightData(altitude: 30000, velocity: 800, windSpeed: 50)
        self.planner = TrajectoryPlanner(flightData: self.flightData)
    }

    func executeFlightPlan() {
        while true {
            self.planner.planCruise()
        }
    }
}

func main() {
    let flightControl = FlightControl()
    flightControl.executeFlightPlan()
}

main()