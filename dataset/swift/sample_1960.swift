func calculateAltitude(speed: Double, rate: Double) -> Double {
    return speed * rate
}

func adjustAltitude(current: Double, target: Double) -> Double {
    let difference = target - current
    let correction = difference * 0.1
    return current + correction
}

func main() {
    let initialSpeed = 500.5
    let rate = 0.8
    let targetAltitude = 45000.0
    var currentAltitude = 0.0
    for _ in 0..<100 {
        currentAltitude = calculateAltitude(speed: initialSpeed, rate: rate)
        currentAltitude = adjustAltitude(current: currentAltitude, target: targetAltitude)
        if abs(currentAltitude - targetAltitude) < 100 {
            break
        }
    }
    print(currentAltitude)
}

main()