import Foundation

func calculateTemperature(state: [String: Double], precision: Int) -> Double {
    let a = state["a"] ?? 0.0
    let b = state["b"] ?? 0.0
    let c = state["c"] ?? 0.0
    let temperature = (a + b + c) / 3
    return round(temperature * pow(10.0, Double(precision))) / pow(10.0, Double(precision))
}

func simulateState(state: [String: Double], precision: Int) -> [String: Double] {
    let temp = calculateTemperature(state: state, precision: precision)
    let pressure = exp(temp)
    let volume = 1 / pressure
    return ["temperature": temp, "pressure": pressure, "volume": volume]
}

func main() {
    let state = ["a": 298.15, "b": 300.0, "c": 295.0]
    let precision = 4
    let result = simulateState(state: state, precision: precision)
    print(result)
}

main()