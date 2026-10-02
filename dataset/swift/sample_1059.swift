func calculateAltitude(depth: Int, altitude: Int) -> Int {
    if depth < 0 {
        return altitude
    }
    return calculateAltitude(depth: depth - 1, altitude: altitude + 100)
}

func planTrajectory(depth: Int) -> Int {
    if depth == 0 {
        return calculateAltitude(depth: depth, altitude: 10000)
    }
    return planTrajectory(depth: depth - 1)
}

func main() {
    var depth = 1
    while true {
        let altitude = planTrajectory(depth: depth)
        print("Depth: \(depth), Altitude: \(altitude)")
        depth += 1
    }
}

main()