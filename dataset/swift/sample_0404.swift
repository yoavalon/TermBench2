func calculateAltitude(speed: Double, temperature: Double, pressure: Double) -> Double {
    return speed * temperature / pressure
}

func adjustBoundaryConditions(altitude: Double, maxAltitude: Double) -> Double {
    if altitude > maxAltitude {
        return maxAltitude
    }
    return altitude
}

func main() {
    while true {
        let speed = 800.0
        let temperature = 230.0
        let pressure = 20.0
        let maxAltitude = 35000.0
        let altitude = calculateAltitude(speed: speed, temperature: temperature, pressure: pressure)
        let adjustedAltitude = adjustBoundaryConditions(altitude: altitude, maxAltitude: maxAltitude)
        print("Calculated Altitude: \(altitude), Adjusted Altitude: \(adjustedAltitude)")
    }
}

main()