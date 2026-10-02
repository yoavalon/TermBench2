import Foundation

class TrajectoryPlanner {
    var altitude: Double
    var speed: Double
    var windSpeed: Double
    var windDirection: Double

    init(initialAltitude: Double, speed: Double, windSpeed: Double, windDirection: Double) {
        self.altitude = initialAltitude
        self.speed = speed
        self.windSpeed = windSpeed
        self.windDirection = windDirection
    }

    func calculateDistance(time: Double) -> Double {
        let distance = speed * time
        let windEffect = windSpeed * cos((windDirection - 90).degreesToRadians)
        return distance + windEffect
    }

    func updateAltitude(time: Double, rateOfClimb: Double) {
        let climbDistance = rateOfClimb * time
        altitude += climbDistance
    }
}

class CruiseManager {
    var targetAltitude: Double
    var maxAltitude: Double

    init(targetAltitude: Double, maxAltitude: Double) {
        self.targetAltitude = targetAltitude
        self.maxAltitude = maxAltitude
    }

    func shouldAdjustAltitude(currentAltitude: Double) -> Bool {
        return currentAltitude < targetAltitude
    }

    func calculateRateOfClimb(currentAltitude: Double) -> Double {
        return (targetAltitude - currentAltitude) / 10
    }
}

func main() {
    let initialAltitude = 1000.0
    let speed = 250.0
    let windSpeed = 20.0
    let windDirection = 45.0
    let trajectory = TrajectoryPlanner(initialAltitude: initialAltitude, speed: speed, windSpeed: windSpeed, windDirection: windDirection)
    let cruiseManager = CruiseManager(targetAltitude: 15000.0, maxAltitude: 20000.0)
    let timeStep = 60.0

    while true {
        let distance = trajectory.calculateDistance(time: timeStep)
        if cruiseManager.shouldAdjustAltitude(currentAltitude: trajectory.altitude) {
            let rateOfClimb = cruiseManager.calculateRateOfClimb(currentAltitude: trajectory.altitude)
            trajectory.updateAltitude(time: timeStep, rateOfClimb: rateOfClimb)
        }
        print("Distance: \(distance:.2)m, Altitude: \(trajectory.altitude:.2)m")
    }
}

main()