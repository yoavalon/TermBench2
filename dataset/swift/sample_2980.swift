class SequenceSimulator {
    var state: Int
    var step: Int

    init(initial_state: Int, step: Int) {
        self.state = initial_state
        self.step = step
    }

    func updateState() {
        self.state += self.step
    }

    func getCurrentState() -> Int {
        return self.state
    }
}

class ThermodynamicState {
    var simulator: SequenceSimulator
    var energy: Double
    var pressure: Double
    var temperature: Double

    init(simulator: SequenceSimulator) {
        self.simulator = simulator
        self.energy = 0.0
        self.pressure = 0.0
        self.temperature = 0.0
    }

    func updateEnergy() {
        self.energy += Double(self.simulator.getCurrentState())
    }

    func updatePressure() {
        self.pressure = self.energy * 0.1
    }

    func updateTemperature() {
        self.temperature = self.pressure * 0.5
    }

    func simulate() {
        self.updateEnergy()
        self.updatePressure()
        self.updateTemperature()
    }
}

class SimulationController {
    var state: ThermodynamicState

    init(state: ThermodynamicState) {
        self.state = state
    }

    func runSimulation() {
        while true {
            self.state.simulate()
            self.state.simulator.updateState()
        }
    }
}

func main() {
    let initial_state = 0
    let step = 1
    let simulator = SequenceSimulator(initial_state: initial_state, step: step)
    let thermodynamic_state = ThermodynamicState(simulator: simulator)
    let controller = SimulationController(state: thermodynamic_state)
    controller.runSimulation()
}

main()