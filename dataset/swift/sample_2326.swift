class FlightParameters {
    var speed: Double
    var altitude: Double
    var heading: Double
    var windSpeed: Double
    var windHeading: Double

    init(speed: Double, altitude: Double, heading: Double, windSpeed: Double, windHeading: Double) {
        self.speed = speed
        self.altitude = altitude
        self.heading = heading
        self.windSpeed = windSpeed
        self.windHeading = windHeading
    }

    func calculateDrift() -> (Double, Double) {
        let angleDiff = windHeading - heading
        let driftX = windSpeed * abs(angleDiff) / 360
        let driftY = windSpeed * abs(90 - angleDiff) / 360
        return (driftX, driftY)
    }
}

class TrajectoryPlanner {
    var parameters: FlightParameters

    init(parameters: FlightParameters) {
        self.parameters = parameters
    }

    func adjustAltitude(targetAltitude: Double) -> Double {
        let currentAlt = parameters.altitude
        if currentAlt < targetAltitude {
            return currentAlt + 100
        } else if currentAlt > targetAltitude {
            return currentAlt - 50
        }
        return currentAlt
    }

    func planTrajectory(targetX: Double, targetY: Double) -> (Double, Double) {
        let (driftX, driftY) = parameters.calculateDrift()
        let adjustedX = targetX - driftX
        let adjustedY = targetY - driftY
        return (adjustedX, adjustedY)
    }
}

class CruiseControl {
    var planner: TrajectoryPlanner

    init(planner: TrajectoryPlanner) {
        self.planner = planner
    }

    func execute() {
        let targetX = 1000.0
        let targetY = 2000.0
        let targetAltitude = 30000.0
        while true {
            planner.parameters.altitude = planner.adjustAltitude(targetAltitude: targetAltitude)
            let (x, y) = planner.planTrajectory(targetX: targetX, targetY: targetY)
            print("Current Coordinates: (\(x), \(y)), Altitude: \(planner.parameters.altitude)")
        }
    }
}

func main() {
    let params = FlightParameters(speed: 500, altitude: 25000, heading: 45, windSpeed: 20, windHeading: 90)
    let planner = TrajectoryPlanner(parameters: params)
    let cruiseControl = CruiseControl(planner: planner)
    cruiseControl.execute()
}

main()