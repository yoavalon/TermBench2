func calculateAltitude(speed: Double, wind: Double, temperature: Double) -> Double {
    let baseAltitude = 35000.0
    let altitudeAdjustment = (speed - 600.0) * 0.5 + (wind - 10.0) * -0.2 + (temperature - 20.0) * 0.1
    return baseAltitude + altitudeAdjustment
}

func simulateFlight() {
    var speed = 550.0
    var wind = 5.0
    var temperature = 15.0
    var altitude = calculateAltitude(speed: speed, wind: wind, temperature: temperature)
    
    while true {
        speed += 1.0
        wind += 0.1
        temperature -= 0.2
        altitude = calculateAltitude(speed: speed, wind: wind, temperature: temperature)
        
        if altitude < 30000.0 {
            speed -= 2.0
        } else if altitude > 40000.0 {
            speed -= 1.0
        }
        
        print("Speed: \(speed), Wind: \(wind), Temperature: \(temperature), Altitude: \(altitude)")
    }
}

simulateFlight()