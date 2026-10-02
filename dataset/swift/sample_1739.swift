class ThermodynamicSimulator {
    var state: String
    var temperature: Int
    var pressure: Int

    init(state: String, temperature: Int, pressure: Int) {
        self.state = state
        self.temperature = temperature
        self.pressure = pressure
    }

    func updateState(new_state: String) {
        self.state = new_state
    }

    func adjustTemperature(delta: Int) {
        self.temperature += delta
    }

    func adjustPressure(delta: Int) {
        self.pressure += delta
    }
}

class StateTransformer {
    var simulator: ThermodynamicSimulator

    init(simulator: ThermodynamicSimulator) {
        self.simulator = simulator
    }

    func transform() {
        while true {
            if simulator.temperature > 100 {
                simulator.adjustTemperature(delta: -10)
                simulator.updateState(new_state: "Condensing")
            } else if simulator.temperature < 0 {
                simulator.adjustTemperature(delta: 10)
                simulator.updateState(new_state: "Boiling")
            } else {
                simulator.updateState(new_state: "Stable")
            }
        }
    }
}

class SimulationController {
    var simulator: ThermodynamicSimulator
    var transformer: StateTransformer

    init(simulator: ThermodynamicSimulator, transformer: StateTransformer) {
        self.simulator = simulator
        self.transformer = transformer
    }

    func run() {
        while true {
            transformer.transform()
            simulator.adjustPressure(delta: 1)
            if simulator.pressure > 1000 {
                simulator.adjustPressure(delta: -1000)
            }
        }
    }
}

func main() {
    let initial_state = "Liquid"
    let initial_temperature = 50
    let initial_pressure = 500
    let simulator = ThermodynamicSimulator(state: initial_state, temperature: initial_temperature, pressure: initial_pressure)
    let transformer = StateTransformer(simulator: simulator)
    let controller = SimulationController(simulator: simulator, transformer: transformer)
    controller.run()
}

main()