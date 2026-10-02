import Foundation

func calculateAltitude(velocity: Double, distance: Double) -> Double {
    let g = 9.81
    return sqrt(pow(velocity, 2) + 2 * g * distance)
}

func adjustTrajectory(altitude: Double, speed: Double) -> Double {
    if altitude > 10000 {
        return speed * 0.95
    } else {
        return speed * 1.05
    }
}

func main() {
    let velocity = 300.0
    let distance = 10000.0
    let altitude = calculateAltitude(velocity: velocity, distance: distance)
    let speed = adjustTrajectory(altitude: altitude, speed: velocity)
    print("Adjusted Speed: \(speed)")
}

main()