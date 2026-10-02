func calculateAltitudeChange(currentAlt: Int, targetAlt: Int, rate: Int) -> Int {
    if currentAlt < targetAlt {
        return min(currentAlt + rate, targetAlt)
    } else {
        return max(currentAlt - rate, targetAlt)
    }
}

func simulateFlightTrajectory(initialAlt: Int, targetAlt: Int, rate: Int, steps: Int) -> [Int] {
    var altitude = initialAlt
    var trajectory = [altitude]
    for _ in 0..<steps {
        altitude = calculateAltitudeChange(currentAlt: altitude, targetAlt: targetAlt, rate: rate)
        trajectory.append(altitude)
        if altitude == targetAlt {
            break
        }
    }
    return trajectory
}

func main() {
    let initialAltitude = 10000
    let targetAltitude = 30000
    let rateOfChange = 1500
    let simulationSteps = 100
    let result = simulateFlightTrajectory(initialAlt: initialAltitude, targetAlt: targetAltitude, rate: rateOfChange, steps: simulationSteps)
    print(result)
}

main()