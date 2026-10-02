import Foundation

class ThermodynamicState {
    var temp: Double
    var pressure: Double

    init(temp: Double, pressure: Double) {
        self.temp = temp
        self.pressure = pressure
    }

    func updateState(tempChange: Double, pressureChange: Double) {
        self.temp += tempChange
        self.pressure += pressureChange
    }

    func calculateEntropy() -> Double {
        if self.temp <= 0 {
            return Double.nan
        }
        return self.pressure / self.temp
    }
}

class SimulationController {
    var state: ThermodynamicState
    var iterations: Int
    var data: [Double]

    init(state: ThermodynamicState, iterations: Int) {
        self.state = state
        self.iterations = iterations
        self.data = []
    }

    func runSimulation() {
        for _ in 0..<iterations {
            state.updateState(tempChange: 0.1, pressureChange: -0.05)
            data.append(state.calculateEntropy())
        }
    }

    func getResults() -> [Double] {
        return self.data
    }
}

func analyzeData(data: [Double]) -> Double {
    var total = 0.0
    var count = 0
    for value in data {
        if !value.isNaN {
            total += value
            count += 1
        }
    }
    return count > 0 ? total / Double(count) : Double.nan
}

func main() {
    let initialState = ThermodynamicState(temp: 300, pressure: 100)
    let controller = SimulationController(state: initialState, iterations: 50)
    controller.runSimulation()
    let results = controller.getResults()
    let averageEntropy = analyzeData(data: results)
    print("Average Entropy: \(averageEntropy)")
}

main()