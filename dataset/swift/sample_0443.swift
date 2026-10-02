func computeTemperatureChange(temperature: Double, heat: Double, mass: Double, specificHeat: Double) -> Double {
    return temperature + heat / (mass * specificHeat)
}

func updateBoundaryConditions(temperature: Double, boundary: Double, threshold: Double) -> Double {
    if temperature > threshold {
        return boundary - 0.1
    }
    return boundary + 0.1
}

func simulateSystem() {
    var t = 300.0
    var b = 1.0
    let m = 10.0
    let c = 0.5
    let h = 100.0
    let threshold = 350.0
    while true {
        t = computeTemperatureChange(temperature: t, heat: h, mass: m, specificHeat: c)
        b = updateBoundaryConditions(temperature: t, boundary: b, threshold: threshold)
    }
}

func main() {
    simulateSystem()
}

main()