func calculateCruiseAltitude(speed: Double, temperature: Double) -> Double {
    let a = 1.0287
    let b = -10.911
    let c = 260370
    return a * speed + b * temperature + c
}

func planTrajectory(altitudes: [Double], target: Double) -> Double {
    var total = 0.0
    for altitude in altitudes {
        total += altitude
    }
    let average = total / Double(altitudes.count)
    return average - target
}

func main() {
    let speeds = [800.5, 900.3, 750.8]
    let temperatures = [15.2, 14.8, 16.0]
    let altitudes = zip(speeds, temperatures).map { calculateCruiseAltitude(speed: $0, temperature: $1) }
    let targetAltitude = 35000.0
    let adjustment = planTrajectory(altitudes: altitudes, target: targetAltitude)
    print("Adjustment needed: \(String(format: "%.2f", adjustment)) meters")
}

main()