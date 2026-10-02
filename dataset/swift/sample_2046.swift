class FlightPlanner {
    var altitude: Int
    var speed: Int
    var heading: Int

    init(altitude: Int, speed: Int, heading: Int) {
        self.altitude = altitude
        self.speed = speed
        self.heading = heading
    }

    func updateAltitude(delta: Int) {
        self.altitude += delta
    }

    func calculateTimeToDestination(distance: Int) -> Double {
        return Double(distance) / Double(self.speed)
    }
}

class TrajectoryCalculator {
    var planner: FlightPlanner

    init(planner: FlightPlanner) {
        self.planner = planner
    }

    func calculateCruiseAltitude() -> Int {
        if self.planner.altitude < 30000 {
            return 30000
        }
        return self.planner.altitude
    }

    func adjustForWinds(windSpeed: Int, windDirection: Int) -> (Int, Int) {
        let adjustedSpeed = self.planner.speed - windSpeed * 0.5
        let adjustedHeading = self.planner.heading + windDirection
        return (adjustedSpeed, adjustedHeading)
    }
}

class FlightAnalyzer {
    var calculator: TrajectoryCalculator

    init(calculator: TrajectoryCalculator) {
        self.calculator = calculator
    }

    func analyze(distance: Int) -> (Int, Int, Int, Double) {
        let cruiseAltitude = self.calculator.calculateCruiseAltitude()
        let (adjustedSpeed, adjustedHeading) = self.calculator.adjustForWinds(windSpeed: 10, windDirection: 5)
        let timeToDestination = self.calculator.planner.calculateTimeToDestination(distance: distance)
        return (cruiseAltitude, adjustedSpeed, adjustedHeading, timeToDestination)
    }
}

func main() {
    let planner = FlightPlanner(altitude: 25000, speed: 500, heading: 90)
    let calculator = TrajectoryCalculator(planner: planner)
    let analyzer = FlightAnalyzer(calculator: calculator)
    let (cruiseAltitude, adjustedSpeed, adjustedHeading, timeToDestination) = analyzer.analyze(distance: 1000)
    print("Cruise Altitude: \(cruiseAltitude)")
    print("Adjusted Speed: \(adjustedSpeed)")
    print("Adjusted Heading: \(adjustedHeading)")
    print("Time to Destination: \(timeToDestination)")
}

main()