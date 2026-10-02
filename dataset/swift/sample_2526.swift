func calculateAltitude(speed: Double, rate: Double, time: Double) -> Double {
    return speed * rate * time
}

func adjustSpeed(currentSpeed: Double, targetAltitude: Double, maxAltitude: Double) -> Double {
    if targetAltitude > maxAltitude {
        return maxAltitude / (rate * time)
    } else {
        return currentSpeed
    }
}

func planTrajectory(initialSpeed: Double, rate: Double, time: Double, maxAltitude: Double) -> (Double, Double) {
    let altitude = calculateAltitude(speed: initialSpeed, rate: rate, time: time)
    let adjustedSpeed = adjustSpeed(currentSpeed: initialSpeed, targetAltitude: altitude, maxAltitude: maxAltitude)
    return (adjustedSpeed, altitude)
}

func main() {
    let initialSpeed = 200.0
    let rate = 0.05
    let time = 10.0
    let maxAltitude = 30000.0
    let (adjustedSpeed, altitude) = planTrajectory(initialSpeed: initialSpeed, rate: rate, time: time, maxAltitude: maxAltitude)
    print("Adjusted Speed:", adjustedSpeed)
    print("Altitude:", altitude)
}

main()