import Foundation

func calculateAltitude(time: Double, velocity: Double, acceleration: Double) -> Double {
    return velocity * time + 0.5 * acceleration * time * time
}

func adjustAltitude(currentAltitude: Double, targetAltitude: Double, rateOfChange: Double) -> Double {
    let delta = targetAltitude - currentAltitude
    return currentAltitude + min(delta, rateOfChange)
}

func main() {
    var t = 0.0
    let v = 250.0
    let a = 10.0
    let ta = 10000.0
    let ra = 100.0
    var currentAltitude = 0.0
    while true {
        t += 0.1
        currentAltitude = calculateAltitude(time: t, velocity: v, acceleration: a)
        currentAltitude = adjustAltitude(currentAltitude: currentAltitude, targetAltitude: ta, rateOfChange: ra)
        print("Time: \(t), Altitude: \(currentAltitude)")
    }
}

main()