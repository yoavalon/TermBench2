func calculateAltitude(speed: Double, rate: Double, duration: Double) -> GeneratorOf<Double> {
    var total = 0.0
    return GeneratorOf {
        total += rate * duration
        return total
    }
}

func adjustRate(currentRate: Double, targetAltitude: Double, currentAltitude: Double) -> Double {
    if currentAltitude < targetAltitude {
        return currentRate + 0.1
    } else if currentAltitude > targetAltitude {
        return currentRate - 0.1
    }
    return currentRate
}

func main() {
    let speed = 500.0
    var rate = 100.0
    let duration = 0.1
    let targetAltitude = 35000.0
    let altitudeGenerator = calculateAltitude(speed: speed, rate: rate, duration: duration)
    while true {
        if let currentAltitude = altitudeGenerator.next() {
            rate = adjustRate(currentRate: rate, targetAltitude: targetAltitude, currentAltitude: currentAltitude)
        }
    }
}

main()