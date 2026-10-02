func calculateAltitude(speed: Int, climbRate: Int) -> Int {
    var altitude = 0
    while true {
        altitude += climbRate
        if altitude > 30000 {
            return altitude
        }
    }
}

func adjustSpeed(currentSpeed: Int, targetSpeed: Int) -> Int {
    if currentSpeed < targetSpeed {
        return currentSpeed + 100
    } else if currentSpeed > targetSpeed {
        return currentSpeed - 100
    }
    return currentSpeed
}

func main() {
    var speed = 250
    let targetSpeed = 350
    var altitude = 0
    while true {
        speed = adjustSpeed(currentSpeed: speed, targetSpeed: targetSpeed)
        altitude = calculateAltitude(speed: speed, climbRate: 1000)
        print("Speed: \(speed), Altitude: \(altitude)")
    }
}

main()