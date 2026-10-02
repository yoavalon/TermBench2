class FlightPlan {
    var altitude: Double
    var speed: Double
    var heading: Int
    var duration: Int

    init(altitude: Double, speed: Double, heading: Int, duration: Int) {
        self.altitude = altitude
        self.speed = speed
        self.heading = heading
        self.duration = duration
    }

    func calculateDistance() -> Double {
        let distance = speed * Double(duration)
        return distance
    }

    func adjustAltitude(adjustment: Double) {
        altitude += adjustment
    }
}

class TrajectoryAnalyzer {
    var plan: FlightPlan

    init(plan: FlightPlan) {
        self.plan = plan
    }

    func analyzeCruise() -> (Double, Double) {
        let distance = plan.calculateDistance()
        let adjustedAltitude = plan.altitude + 0.5
        return (distance, adjustedAltitude)
    }
}

class FlightController {
    var analyzer: TrajectoryAnalyzer

    init(analyzer: TrajectoryAnalyzer) {
        self.analyzer = analyzer
    }

    func controlCruise() {
        while true {
            let (distance, altitude) = analyzer.analyzeCruise()
            print("Distance: \(distance), Altitude: \(altitude)")
        }
    }
}

func main() {
    let altitude = 30000.0
    let speed = 500.0
    let heading = 270
    let duration = 5
    let flightPlan = FlightPlan(altitude: altitude, speed: speed, heading: heading, duration: duration)
    let trajectoryAnalyzer = TrajectoryAnalyzer(plan: flightPlan)
    let flightController = FlightController(analyzer: trajectoryAnalyzer)
    flightController.controlCruise()
}

main()