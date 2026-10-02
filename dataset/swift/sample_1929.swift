import Foundation
import Accelerate

func simulateTemperatureChange(initialTemp: Double, rate: Double, steps: Int) -> Double {
    var temperature = initialTemp
    for _ in 0..<steps {
        let randomValue = Darwin.random()
        temperature += rate * randomValue
    }
    return temperature
}

func analyzeSimulationResults(initialTemp: Double, finalTemp: Double) -> Double {
    return finalTemp - initialTemp
}

func main() {
    let initialTemperature = 300.0
    let rateOfChange = 0.5
    let numberOfSteps = 1000
    let finalTemperature = simulateTemperatureChange(initialTemp: initialTemperature, rate: rateOfChange, steps: numberOfSteps)
    let temperatureDifference = analyzeSimulationResults(initialTemp: initialTemperature, finalTemp: finalTemperature)
    print("Initial Temperature: \(initialTemperature), Final Temperature: \(finalTemperature), Change: \(temperatureDifference)")
}

main()