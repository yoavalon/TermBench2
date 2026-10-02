class FlightPlanner {
    var altitude: Double
    var target: Double
    var speed: Double
    var descent: Double
    var time: Int

    init(initialAltitude: Double, targetAltitude: Double, speed: Double, descentRate: Double) {
        self.altitude = initialAltitude
        self.target = targetAltitude
        self.speed = speed
        self.descent = descentRate
        self.time = 0
    }

    func updateAltitude() {
        if altitude > target {
            altitude -= descent * speed
            time += 1
        } else {
            altitude = target
        }
    }

    func getFlightData() -> (Double, Int) {
        return (altitude, time)
    }
}

class TrajectoryAnalyzer {
    var planner: FlightPlanner

    init(planner: FlightPlanner) {
        self.planner = planner
    }

    func analyze() -> [(Double, Int)] {
        var data: [(Double, Int)] = []
        while planner.altitude > planner.target {
            planner.updateAltitude()
            data.append(planner.getFlightData())
        }
        return data
    }
}

func main() {
    let initialAltitude = 35000.0
    let targetAltitude = 10000.0
    let speed = 0.5
    let descentRate = 100.0
    let planner = FlightPlanner(initialAltitude: initialAltitude, targetAltitude: targetAltitude, speed: speed, descentRate: descentRate)
    let analyzer = TrajectoryAnalyzer(planner: planner)
    let trajectoryData = analyzer.analyze()
    for (altitude, time) in trajectoryData {
        print("Time: \(time), Altitude: \(altitude)")
    }
}

main()