class ThermodynamicSimulation {
    var state: String
    var energy: Int
    var temperature: Int

    init(state: String, energy: Int, temperature: Int) {
        self.state = state
        self.energy = energy
        self.temperature = temperature
    }

    func updateState() {
        if temperature > 300 {
            state = "high"
        } else if temperature < 100 {
            state = "low"
        } else {
            state = "stable"
        }
    }

    func adjustEnergy() {
        if state == "high" {
            energy -= 10
        } else if state == "low" {
            energy += 10
        }
    }

    func simulate() {
        updateState()
        adjustEnergy()
        temperature = energy / 10
    }
}

func recursiveSimulation(_ simulator: ThermodynamicSimulation) {
    simulator.simulate()
    recursiveSimulation(simulator)
}

func main() {
    let initialState = "unknown"
    let initialEnergy = 250
    let initialTemperature = 220
    let simulator = ThermodynamicSimulation(state: initialState, energy: initialEnergy, temperature: initialTemperature)
    recursiveSimulation(simulator)
}

main()