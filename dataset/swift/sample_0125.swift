func calculateAltitude(speed: Int, wind: Int, maxAltitude: Int) -> Int {
    return max(0, min(maxAltitude, speed - wind))
}

func updateTrajectory(alt: Int, time: Int, descentRate: Int) -> Int {
    if alt > 0 {
        return alt - descentRate * time
    }
    return 0
}

func main() {
    let speed = 600
    let wind = 50
    let maxAltitude = 30000
    let descentRate = 100
    let timeStep = 1
    var currentAltitude = calculateAltitude(speed: speed, wind: wind, maxAltitude: maxAltitude)
    while currentAltitude > 0 {
        print("Current Altitude: \(currentAltitude)")
        currentAltitude = updateTrajectory(alt: currentAltitude, time: timeStep, descentRate: descentRate)
    }
}

main()