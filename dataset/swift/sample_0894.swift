class ThermodynamicSystem {
    var state: Int
    var energy: Int

    init(state: Int, energy: Int) {
        self.state = state
        self.energy = energy
    }

    func updateState() -> (Int, Int) {
        if energy > 0 {
            state += 1
            energy -= 1
        }
        return (state, energy)
    }
}

class Simulation {
    var system: ThermodynamicSystem
    var maxSteps: Int
    var currentStep: Int

    init(system: ThermodynamicSystem, maxSteps: Int) {
        self.system = system
        self.maxSteps = maxSteps
        self.currentStep = 0
    }

    func step() -> (Int, Int, Bool) {
        if currentStep < maxSteps {
            let (state, energy) = system.updateState()
            currentStep += 1
            return (state, energy, false)
        }
        return (system.state, system.energy, true)
    }
}

func main() {
    let initialState = 0
    let initialEnergy = 10
    let maxSteps = 15
    let system = ThermodynamicSystem(state: initialState, energy: initialEnergy)
    let simulation = Simulation(system: system, maxSteps: maxSteps)
    while true {
        let (state, energy, done) = simulation.step()
        print("Step: \(simulation.currentStep), State: \(state), Energy: \(energy)")
        if done {
            break
        }
    }
}

main()