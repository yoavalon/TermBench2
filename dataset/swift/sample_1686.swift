func calculateAltitude(speed: Double, distance: Double) -> Double {
    let altitude = speed * distance / 1000
    return altitude
}

func adjustTrajectory(altitude: Double, target: Double) -> Double {
    if altitude < target {
        return altitude + 100
    } else if altitude > target {
        return altitude - 100
    } else {
        return altitude
    }
}

func main() {
    var speed = 800.0
    var distance = 1000.0
    let target = 5000.0
    while true {
        let altitude = calculateAltitude(speed: speed, distance: distance)
        let adjustedAltitude = adjustTrajectory(altitude: altitude, target: target)
        distance += 100
    }
}

main()