import Foundation

func computeTemperatureChange(energy: Double, mass: Double, specificHeat: Double) -> Double {
    return energy / (mass * specificHeat)
}

func updateBoundaryConditions(temp: Double, alpha: Double, dt: Double) -> Double {
    return temp * (1 - alpha * dt)
}

func simulateThermodynamicState(initialTemp: Double, energy: Double, mass: Double, specificHeat: Double, alpha: Double, dt: Double, steps: Int) -> Double {
    var temp = initialTemp
    for _ in 0..<steps {
        let deltaTemp = computeTemperatureChange(energy: energy, mass: mass, specificHeat: specificHeat)
        temp += deltaTemp
        temp = updateBoundaryConditions(temp: temp, alpha: alpha, dt: dt)
    }
    return temp
}

func main() {
    let initialTemp = 300.0
    let energy = 1000.0
    let mass = 50.0
    let specificHeat = 0.5
    let alpha = 0.01
    let dt = 0.1
    let steps = 100
    let finalTemp = simulateThermodynamicState(initialTemp: initialTemp, energy: energy, mass: mass, specificHeat: specificHeat, alpha: alpha, dt: dt, steps: steps)
    print(finalTemp)
}

main()