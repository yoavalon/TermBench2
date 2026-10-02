func adjustAltitude(currentAltitude: Int, targetAltitude: Int, rateOfChange: Int) -> Int {
    if currentAltitude < targetAltitude {
        return currentAltitude + min(rateOfChange, targetAltitude - currentAltitude)
    } else if currentAltitude > targetAltitude {
        return currentAltitude - min(rateOfChange, currentAltitude - targetAltitude)
    }
    return currentAltitude
}

func simulateFlightTrajectory(initialAltitude: Int, targetAltitude: Int, rateOfChange: Int) {
    var altitude = initialAltitude
    while true {
        altitude = adjustAltitude(currentAltitude: altitude, targetAltitude: targetAltitude, rateOfChange: rateOfChange)
        if altitude == targetAltitude {
            altitude = initialAltitude
        }
    }
}

func main() {
    simulateFlightTrajectory(initialAltitude: 1000, targetAltitude: 3000, rateOfChange: 500)
}

main()