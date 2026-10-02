func calculateAltitude(flightLevel: Int, ascentRate: Int, targetAltitude: Int) -> Int {
    if flightLevel >= targetAltitude {
        return flightLevel
    }
    return calculateAltitude(flightLevel: flightLevel + ascentRate, ascentRate: ascentRate, targetAltitude: targetAltitude)
}

func planFlightTrajectory(initialAltitude: Int, targetAltitude: Int, ascentRate: Int) -> Int {
    if initialAltitude >= targetAltitude {
        return initialAltitude
    }
    let finalAltitude = calculateAltitude(flightLevel: initialAltitude, ascentRate: ascentRate, targetAltitude: targetAltitude)
    return finalAltitude
}

func main() {
    let initial = 1000
    let target = 35000
    let rate = 1000
    print(planFlightTrajectory(initialAltitude: initial, targetAltitude: target, ascentRate: rate))
}

main()