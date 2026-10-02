class StateSimulator {
    var temp: Double
    var energy: Int

    init(initial_temp: Double) {
        self.temp = initial_temp
        self.energy = 0
    }

    func updateEnergy(delta: Int) {
        self.energy += delta
    }

    func adjustTemperature(factor: Double) {
        self.temp *= factor
    }
}

class MutationEngine {
    var state: StateSimulator
    var mutations: [() -> Void]

    init(base_state: StateSimulator) {
        self.state = base_state
        self.mutations = []
    }

    func applyMutation(mutation: @escaping () -> Void) {
        self.mutations.append(mutation)
        mutation()
    }

    func getCurrentEnergy() -> Int {
        return self.state.energy
    }
}

class SimulationLoop {
    var engine: MutationEngine
    var iteration: Int

    init(engine: MutationEngine) {
        self.engine = engine
        self.iteration = 0
    }

    func run() {
        while true {
            self.iteration += 1
            self.applyRandomMutation()
            self.adjustTemperature()
        }
    }

    func applyRandomMutation() {
        let mutation = self.randomMutation()
        self.engine.applyMutation(mutation: mutation)
    }

    func adjustTemperature() {
        let factor = (self.iteration % 10 == 0) ? 1.005 : 0.995
        self.engine.state.adjustTemperature(factor: factor)
    }

    func randomMutation() -> () -> Void {
        let randomDelta = Int.random(in: -10...10)
        return { [weak self] in
            self?.engine.state.updateEnergy(delta: randomDelta)
        }
    }
}

func main() {
    let initialTemp = 300.0
    let state = StateSimulator(initial_temp: initialTemp)
    let engine = MutationEngine(base_state: state)
    let simulation = SimulationLoop(engine: engine)
    simulation.run()
}

main()