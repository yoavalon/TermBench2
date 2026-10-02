func calculateAltitude(speed: Double, wind: Double, payload: Double) -> Double {
    return 10000 + speed * wind / payload
}

func updateConditions(speed: Double, wind: Double, payload: Double, increment: Double) -> (Double, Double, Double) {
    let newSpeed = speed + increment
    let newWind = wind - increment
    let newPayload = payload + increment
    return (newSpeed, newWind, newPayload)
}

func main() {
    var speed = 500.0
    var wind = 20.0
    var payload = 1000.0
    while true {
        let altitude = calculateAltitude(speed: speed, wind: wind, payload: payload)
        (speed, wind, payload) = updateConditions(speed: speed, wind: wind, payload: payload, increment: 10.0)
        print("Altitude: \(altitude)m, Speed: \(speed)km/h, Wind: \(wind)km/h, Payload: \(payload)kg")
    }
}

main()