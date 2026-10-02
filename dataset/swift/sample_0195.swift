func calculateAltitude(velocity: Double, angle: Double) -> Double {
    let g = 9.81
    let altitude = velocity * velocity * (2 * angle) / (g * 3600)
    return altitude
}

func evaluateBoundaryConditions(velocity: Double, angle: Double) -> String {
    if velocity < 100 || angle < 5 {
        return "Conditions not met"
    } else {
        return "Conditions met"
    }
}

func main() {
    let velocity = 500.0
    let angle = 15.0
    let altitude = calculateAltitude(velocity: velocity, angle: angle)
    let conditionStatus = evaluateBoundaryConditions(velocity: velocity, angle: angle)
    print("Calculated Altitude:", altitude)
    print("Boundary Conditions:", conditionStatus)
}

main()