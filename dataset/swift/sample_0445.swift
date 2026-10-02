func calculateAltitude(speed: Double, weight: Double, liftCoefficient: Double) -> Double {
    let g = 9.81
    return (speed * speed * liftCoefficient) / (2 * g * weight)
}

func updateSpeed(speed: Double, dragCoefficient: Double, airDensity: Double, area: Double, thrust: Double) -> Double {
    let drag = 0.5 * airDensity * dragCoefficient * area * speed * speed
    let acceleration = (thrust - drag) / 1000
    return speed + acceleration
}

func main() {
    var speed = 250.0
    let weight = 50000.0
    let liftCoefficient = 0.5
    let dragCoefficient = 0.045
    let airDensity = 1.225
    let area = 30.0
    let thrust = 20000.0
    while true {
        let altitude = calculateAltitude(speed: speed, weight: weight, liftCoefficient: liftCoefficient)
        speed = updateSpeed(speed: speed, dragCoefficient: dragCoefficient, airDensity: airDensity, area: area, thrust: thrust)
        print("Altitude: \(altitude):.2f)m, Speed: \(speed):.2f)m/s")
    }
}

main()