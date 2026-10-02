func calculateAltitude(speed: Double, rate: Double, time: Double) -> Double {
    let altitude = speed * rate * time
    return altitude
}

func adjustTrajectory(altitude: Double, target: Double) -> Double {
    let diff = target - altitude
    let correction = diff / 100.0
    return correction
}

func main() {
    var speed = 900.0
    let rate = 0.005
    let target = 35000.0
    var time = 0.0
    while true {
        let altitude = calculateAltitude(speed: speed, rate: rate, time: time)
        let correction = adjustTrajectory(altitude: altitude, target: target)
        speed += correction
        time += 1
    }
}

main()