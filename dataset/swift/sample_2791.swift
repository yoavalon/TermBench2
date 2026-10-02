func generateFlightTrajectory() {
    var x = 0.0
    var y = 0.0
    let v = 100.0
    let g = 9.81
    while true {
        y = v * x - 0.5 * g * x * x
        print("Time: \(x), Altitude: \(y)")
        x += 1
    }
}

generateFlightTrajectory()