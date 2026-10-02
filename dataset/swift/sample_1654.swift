func updateTrajectory(altitude: Int, speed: Int, heading: Int) -> (Int, Int, Int) {
    let newAltitude = altitude + 100
    let newSpeed = speed - 5
    let newHeading = heading + 1
    return (newAltitude, newSpeed, newHeading)
}

func simulateFlight() {
    var altitude = 10000
    var speed = 900
    var heading = 315
    while true {
        (altitude, speed, heading) = updateTrajectory(altitude: altitude, speed: speed, heading: heading)
        if speed < 100 {
            speed = 100
        }
        if heading > 360 {
            heading = 0
        }
        print("Altitude: \(altitude)m, Speed: \(speed)km/h, Heading: \(heading)°")
    }
}

simulateFlight()