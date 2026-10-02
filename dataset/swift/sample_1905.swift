import Foundation

func calculateAltitude() -> Double? {
    let a = 1.0, b = 2.0, c = 3.0
    let delta = b * b - 4 * a * c
    if delta >= 0 {
        return (-b + sqrt(delta)) / (2 * a)
    } else {
        return nil
    }
}

func planTrajectory() -> (Double?, Double?) {
    if let altitude = calculateAltitude() {
        let speed = 0.8 * altitude
        return (speed, altitude)
    } else {
        return (nil, nil)
    }
}

func main() {
    let (speed, altitude) = planTrajectory()
    if let speed = speed, let altitude = altitude {
        print("Speed: \(speed), Altitude: \(altitude)")
    } else {
        print("No valid trajectory.")
    }
}

main()