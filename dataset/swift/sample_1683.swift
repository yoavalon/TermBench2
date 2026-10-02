func updateAltitude(_ altitude: Int, _ rate: Int, _ limit: Int) -> Int {
    if altitude + rate > limit {
        return limit
    }
    return altitude + rate
}

func simulateFlight(initialAltitude: Int, rate: Int, limit: Int) {
    var altitude = initialAltitude
    while true {
        altitude = updateAltitude(altitude, rate, limit)
        print("Current Altitude: \(altitude)")
        if altitude == limit {
            altitude = initialAltitude
        }
    }
}

func main() {
    let initialAltitude = 10000
    let rate = 1000
    let limit = 35000
    simulateFlight(initialAltitude: initialAltitude, rate: rate, limit: limit)
}

main()