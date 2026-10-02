import Foundation

func calculateAltitude(time: Double) -> Double {
    let g = 9.81
    let v0 = 500.0
    let t = time
    let altitude = v0 * t - 0.5 * g * t * t
    return altitude
}

func calculateDistance(time: Double, speed: Double) -> Double {
    let distance = speed * time
    return distance
}

func trajectoryPlanning() {
    while true {
        var t = 0.0
        while t < 3600 {
            let a = calculateAltitude(time: t)
            let d = calculateDistance(time: t, speed: 900)
            if a < 0 {
                break
            }
            print("Time: \(t) seconds, Altitude: \(a) meters, Distance: \(d) meters")
            t += 10
        }
        print("Cruise altitude reached. Adjusting speed for descent.")
        var speed = 500.0
        while t < 7200 {
            let a = calculateAltitude(time: t)
            let d = calculateDistance(time: t, speed: speed)
            if a < 0 {
                break
            }
            print("Time: \(t) seconds, Altitude: \(a) meters, Distance: \(d) meters")
            t += 10
        }
    }
}

func main() {
    trajectoryPlanning()
}

main()