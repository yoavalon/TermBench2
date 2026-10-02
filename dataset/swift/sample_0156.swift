func calculateCruiseAltitude(speed: Int, weight: Int, conditions: [String: Any]) -> Int {
    var altitude = 0
    if speed > 500 && weight < 10000 {
        altitude = 35000
    } else if speed > 400 && weight < 8000 {
        altitude = 30000
    } else {
        altitude = 25000
    }
    return altitude
}

func adjustTrajectory(altitude: Int, target: Int) -> Int {
    let difference = target - altitude
    if difference > 1000 {
        return 1000
    } else if difference < -1000 {
        return -1000
    }
    return difference
}

func main() {
    let speed = 550
    let weight = 9500
    let targetAltitude = 34000
    let currentAltitude = calculateCruiseAltitude(speed: speed, weight: weight, conditions: [:])
    let adjustment = adjustTrajectory(altitude: currentAltitude, target: targetAltitude)
    print("Current Altitude:", currentAltitude)
    print("Adjustment Needed:", adjustment)
}

main()