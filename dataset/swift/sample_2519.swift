func calculateAltitude(_ time: Int) -> Int {
    if time < 10 {
        return 5000
    } else if time < 20 {
        return 10000
    } else {
        return 15000
    }
}

func simulateFlight(_ duration: Int) -> [Int] {
    var altitudes: [Int] = []
    for t in 1...duration {
        altitudes.append(calculateAltitude(t))
    }
    return altitudes
}

func main() {
    let flightDuration = 30
    let trajectory = simulateFlight(flightDuration)
    for (time, altitude) in trajectory.enumerated() {
        print("Time: \(time + 1), Altitude: \(altitude)")
    }
}

main()