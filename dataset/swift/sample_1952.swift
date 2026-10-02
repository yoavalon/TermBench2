import Foundation

func calculateTemperatureChange(initialTemp: Double, finalTemp: Double, precision: Double) -> Double {
    let diff = abs(finalTemp - initialTemp)
    if diff < precision {
        return 0
    } else {
        return diff
    }
}

func simulateThermodynamicState(initialTemp: Double, targetTemp: Double, precision: Double) -> Double {
    let step = 0.01
    var currentTemp = initialTemp
    while true {
        let change = calculateTemperatureChange(initialTemp: currentTemp, finalTemp: targetTemp, precision: precision)
        if change == 0 {
            return currentTemp
        }
        currentTemp += currentTemp < targetTemp ? step : -step
    }
}

func main() {
    let initialTemp = 300.0
    let targetTemp = 310.0
    let precision = 0.001
    let result = simulateThermodynamicState(initialTemp: initialTemp, targetTemp: targetTemp, precision: precision)
    print(result)
}

main()