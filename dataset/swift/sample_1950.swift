import Foundation

func calculateAltitude(distance: Double, speed: Double, time: Double) -> Double {
    return distance / (speed * time)
}

func adjustPrecision(altitude: Double, precision: Int) -> Double {
    let factor = pow(10.0, Double(precision))
    return round(altitude * factor) / factor
}

func main() {
    let dist = 1200.5
    let spd = 300.25
    let t = 2.0
    let precision = 2
    let alt = calculateAltitude(distance: dist, speed: spd, time: t)
    let adjustedAlt = adjustPrecision(altitude: alt, precision: precision)
    print("Cruise Altitude: \(adjustedAlt)")
}

main()