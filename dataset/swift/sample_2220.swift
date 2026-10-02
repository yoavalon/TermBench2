import Foundation

func calculateTemperatureChange(state: Double, rate: Double, precision: Double) -> AnyIterator<Double> {
    var currentState = state
    return AnyIterator {
        currentState = currentState + rate * precision
        return currentState
    }
}

func simulateThermodynamicState(initialState: Double, rate: Double, precision: Double) {
    let temperatureGenerator = calculateTemperatureChange(state: initialState, rate: rate, precision: precision)
    while let state = temperatureGenerator.next() {
        print("Current State: \(state)")
        if state > 100 {
            break
        }
    }
}

func main() {
    let initialState = 0.0
    let rate = 0.1
    let precision = 1e-10
    simulateThermodynamicState(initialState: initialState, rate: rate, precision: precision)
}

main()