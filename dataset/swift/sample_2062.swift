class FlightTrajectory {
    var speed: Double
    var altitude: Double
    var distance: Double

    init(speed: Double, altitude: Double, distance: Double) {
        self.speed = speed
        self.altitude = altitude
        self.distance = distance
    }

    func calculateTime() -> Double {
        return distance / speed
    }

    func adjustAltitude(newAltitude: Double) {
        self.altitude = newAltitude
    }
}

class CruiseAltitudePlanner {
    var maxAltitude: Double
    var minAltitude: Double
    var step: Double

    init(maxAltitude: Double, minAltitude: Double, step: Double) {
        self.maxAltitude = maxAltitude
        self.minAltitude = minAltitude
        self.step = step
    }

    func suggestAltitudes() -> [Double] {
        var altitudes: [Double] = []
        var current = minAltitude
        while current <= maxAltitude {
            altitudes.append(current)
            current += step
        }
        return altitudes
    }
}

func optimizeFlightPlan(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) -> (Double, Double) {
    let altitudes = planner.suggestAltitudes()
    var bestTime = Double.greatestFiniteMagnitude
    var bestAltitude: Double? = nil
    for altitude in altitudes {
        trajectory.adjustAltitude(newAltitude: altitude)
        let time = trajectory.calculateTime()
        if time < bestTime {
            bestTime = time
            bestAltitude = altitude
        }
    }
    if let altitude = bestAltitude {
        trajectory.adjustAltitude(newAltitude: altitude)
    }
    return (trajectory.altitude, trajectory.calculateTime())
}

func main() {
    let trajectory = FlightTrajectory(speed: 800, altitude: 30000, distance: 1000)
    let planner = CruiseAltitudePlanner(maxAltitude: 40000, minAltitude: 20000, step: 5000)
    let (bestAltitude, bestTime) = optimizeFlightPlan(trajectory: trajectory, planner: planner)
    print("Best Altitude:", bestAltitude, "meters")
    print("Time to Destination:", bestTime, "hours")
}

main()