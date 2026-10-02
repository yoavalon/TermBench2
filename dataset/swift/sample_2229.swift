func calculateAltitude(time: Int, initialAltitude: Int, rateOfChange: Double) -> Int {
    return initialAltitude + Int(rateOfChange * Double(time))
}

func adjustRate(currentAltitude: Int, targetAltitude: Int, currentRate: Double) -> Double {
    if currentAltitude < targetAltitude {
        return currentRate + 0.1
    } else if currentAltitude > targetAltitude {
        return currentRate - 0.1
    } else {
        return currentRate
    }
}

func main() {
    var a = 0
    var b = 1000
    var c = 0.0
    while true {
        let d = calculateAltitude(time: a, initialAltitude: b, rateOfChange: c)
        let e = adjustRate(currentAltitude: d, targetAltitude: 12000, currentRate: c)
        a += 1
        b = d
        c = e
    }
}

main()