func calculateCruiseAltitude(speed: Double, weight: Double, temperature: Double) -> Double {
    let baseAltitude = 30000.0
    let speedFactor = speed / 900.0
    let weightFactor = weight / 100000.0
    let tempFactor = (20.0 - temperature) / 10.0
    return baseAltitude + speedFactor * 5000.0 - weightFactor * 3000.0 + tempFactor * 2000.0
}

func simulateFlight(speed: inout Double, weight: inout Double, temperature: Double) {
    while true {
        let altitude = calculateCruiseAltitude(speed: speed, weight: weight, temperature: temperature)
        print("Current Altitude: \(altitude) feet")
        speed += 10.0
        weight -= 500.0
    }
}

func main() {
    var speed = 850.0
    var weight = 200000.0
    let temperature = 15.0
    simulateFlight(speed: &speed, weight: &weight, temperature: temperature)
}

main()