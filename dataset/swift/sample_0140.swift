func simulateState(temp: Double, pressure: Double, volume: Double) -> (Double, Double) {
    let internalEnergy = temp * volume * pressure
    let entropy = internalEnergy / (temp * pressure)
    return (internalEnergy, entropy)
}

func checkBoundaryConditions(temp: Double, pressure: Double, volume: Double) -> Bool {
    let maxTemp = 1000.0
    let minPressure = 1.0
    let maxVolume = 1000.0
    if temp > maxTemp || pressure < minPressure || volume > maxVolume {
        return false
    }
    return true
}

func main() {
    let temp = 500.0
    let pressure = 2.0
    let volume = 500.0
    if checkBoundaryConditions(temp: temp, pressure: pressure, volume: volume) {
        let (internalEnergy, entropy) = simulateState(temp: temp, pressure: pressure, volume: volume)
        print("Simulation Complete:", internalEnergy, entropy)
    } else {
        print("Boundary conditions exceeded")
    }
}

main()