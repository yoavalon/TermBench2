import Foundation

func calculatePressure(_ temperature: Double, _ volume: Double) -> Double {
    return 0.0821 * temperature / volume
}

func updateTemperature(_ temp: Double, _ heatAdded: Double, _ heatCapacity: Double) -> Double {
    return temp + heatAdded / heatCapacity
}

func main() {
    var temp = 300.0
    let vol = 22.4
    let heatCap = 25.0
    let heatAdded = 1000.0
    let maxIterations = 10
    
    for _ in 0..<maxIterations {
        let pressure = calculatePressure(temp, vol)
        temp = updateTemperature(temp, heatAdded, heatCap)
        print("Pressure: \(String(format: "%.2f", pressure)) atm, Temperature: \(String(format: "%.2f", temp)) K")
    }
}

main()