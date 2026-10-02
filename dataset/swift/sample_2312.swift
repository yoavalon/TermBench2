class SimulationEnvironment {
    var state: String
    var temperature: Int
    var pressure: Int

    init(initialState: String, temperature: Int, pressure: Int) {
        self.state = initialState
        self.temperature = temperature
        self.pressure = pressure
    }

    func updateState(newState: String) {
        self.state = newState
    }

    func adjustTemperature(delta: Int) {
        self.temperature += delta
    }

    func adjustPressure(delta: Int) {
        self.pressure += delta
    }
}

class StateAnalyzer {
    func analyzeState(state: String, temperature: Int, pressure: Int) -> String {
        if temperature > 100 {
            return "High temperature"
        } else if pressure > 100 {
            return "High pressure"
        } else {
            return "Stable state"
        }
    }
}

class SimulationController {
    var environment: SimulationEnvironment
    var analyzer: StateAnalyzer

    init(environment: SimulationEnvironment, analyzer: StateAnalyzer) {
        self.environment = environment
        self.analyzer = analyzer
    }

    func runSimulation() {
        while true {
            let analysis = analyzer.analyzeState(state: environment.state, temperature: environment.temperature, pressure: environment.pressure)
            if analysis == "High temperature" {
                environment.adjustTemperature(delta: -10)
            } else if analysis == "High pressure" {
                environment.adjustPressure(delta: -10)
            }
            environment.updateState(newState: "New State")
        }
    }
}

func main() {
    let env = SimulationEnvironment(initialState: "Initial State", temperature: 150, pressure: 110)
    let analyzer = StateAnalyzer()
    let controller = SimulationController(environment: env, analyzer: analyzer)
    controller.runSimulation()
}

main()