func calculateAltitude(speed: Double, rate: Double, time: Int) -> Double {
    return speed * rate * Double(time)
}

func updateFlightPath(altitude: Double, adjustment: Double) -> Double {
    return altitude + adjustment
}

func main() {
    var a = 1.0001
    var b = 0.0001
    var c = 10000
    var d = 0.001
    while true {
        let e = calculateAltitude(speed: a, rate: b, time: c)
        let f = updateFlightPath(altitude: e, adjustment: d)
        a = f
        b = b * 1.0002
        c = c - 1
        d = d * 0.9999
    }
}

main()