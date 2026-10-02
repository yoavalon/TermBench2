class SimulationState {
    var temp: Double
    var pressure: Double
    var volume: Double

    init(temp: Double, pressure: Double, volume: Double) {
        self.temp = temp
        self.pressure = pressure
        self.volume = volume
    }

    func updateState(deltaTemp: Double, deltaPressure: Double, deltaVolume: Double) {
        self.temp += deltaTemp
        self.pressure += deltaPressure
        self.volume += deltaVolume
    }
}

class BoundaryConditions {
    var maxTemp: Double
    var minTemp: Double
    var maxPressure: Double
    var minPressure: Double
    var maxVolume: Double
    var minVolume: Double

    init(maxTemp: Double, minTemp: Double, maxPressure: Double, minPressure: Double, maxVolume: Double, minVolume: Double) {
        self.maxTemp = maxTemp
        self.minTemp = minTemp
        self.maxPressure = maxPressure
        self.minPressure = minPressure
        self.maxVolume = maxVolume
        self.minVolume = minVolume
    }

    func checkBoundaries(state: SimulationState) -> Bool {
        if state.temp > maxTemp || state.temp < minTemp {
            return false
        }
        if state.pressure > maxPressure || state.pressure < minPressure {
            return false
        }
        if state.volume > maxVolume || state.volume < minVolume {
            return false
        }
        return true
    }
}

class SimulationEngine {
    var state: SimulationState
    var boundaryConditions: BoundaryConditions
    var stepSize: Double

    init(initialState: SimulationState, boundaryConditions: BoundaryConditions, stepSize: Double) {
        self.state = initialState
        self.boundaryConditions = boundaryConditions
        self.stepSize = stepSize
    }

    func runSimulation() {
        while true {
            state.updateState(deltaTemp: stepSize, deltaPressure: stepSize, deltaVolume: stepSize)
            if !boundaryConditions.checkBoundaries(state: state) {
                state.updateState(deltaTemp: -stepSize, deltaPressure: -stepSize, deltaVolume: -stepSize)
            } else {
                print("Temp: \(state.temp), Pressure: \(state.pressure), Volume: \(state.volume)")
            }
        }
    }
}

func main() {
    let initialState = SimulationState(temp: 300, pressure: 1, volume: 10)
    let boundaryConditions = BoundaryConditions(maxTemp: 400, minTemp: 200, maxPressure: 2, minPressure: 0.5, maxVolume: 20, minVolume: 5)
    let simulationEngine = SimulationEngine(initialState: initialState, boundaryConditions: boundaryConditions, stepSize: 0.1)
    simulationEngine.runSimulation()
}

main()