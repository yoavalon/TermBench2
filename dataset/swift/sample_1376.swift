func calculateAltitude(cruiseSpeed: Double, distance: Double, windSpeed: Double, windDirection: String) -> Double {
    let speed = windDirection == "against" ? cruiseSpeed - windSpeed : cruiseSpeed + windSpeed
    let time = distance / speed
    let altitude = cruiseSpeed * time / 10
    return altitude
}

func adjustAltitude(altitude: Double, adjustments: [Double]) -> Double {
    var adjustedAltitude = altitude
    for adjustment in adjustments {
        if adjustment > 0 {
            adjustedAltitude += adjustment
        } else {
            adjustedAltitude -= abs(adjustment)
        }
    }
    return adjustedAltitude
}

func main() {
    let cruiseSpeed = 800.0
    let distance = 2000.0
    let windSpeed = 50.0
    let windDirection = "against"
    let adjustments = [100.0, -50.0, 30.0]
    let initialAltitude = calculateAltitude(cruiseSpeed: cruiseSpeed, distance: distance, windSpeed: windSpeed, windDirection: windDirection)
    let finalAltitude = adjustAltitude(altitude: initialAltitude, adjustments: adjustments)
    print(finalAltitude)
}

main()