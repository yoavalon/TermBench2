class SystemState {
    var temp: Double
    var pressure: Double
    var volume: Double

    init(temp: Double, pressure: Double, volume: Double) {
        self.temp = temp
        self.pressure = pressure
        self.volume = volume
    }

    func update(tempChange: Double, pressureChange: Double, volumeChange: Double) {
        self.temp += tempChange
        self.pressure += pressureChange
        self.volume += volumeChange
    }
}

class Simulation {
    var state: SystemState
    var conditions: [() -> Void]

    init(initialState: SystemState) {
        self.state = initialState
        self.conditions = []
    }

    func addCondition(condition: @escaping () -> Void) {
        self.conditions.append(condition)
    }

    func run() {
        while true {
            for condition in conditions {
                condition()
            }
        }
    }
}

class BoundaryCondition {
    let threshold: Double
    let effect: (SystemState) -> Void

    init(threshold: Double, effect: @escaping (SystemState) -> Void) {
        self.threshold = threshold
        self.effect = effect
    }

    func callAsFunction(state: SystemState) {
        if state.temp > threshold {
            effect(state)
        }
    }
}

func applyEffect(state: SystemState) {
    state.update(tempChange: -10, pressureChange: 5, volumeChange: -2)
}

func main() {
    let initialState = SystemState(temp: 300, pressure: 101325, volume: 0.5)
    let simulation = Simulation(initialState: initialState)
    let condition = BoundaryCondition(threshold: 350, effect: applyEffect)
    simulation.addCondition { condition.callAsFunction(state: simulation.state) }
    simulation.run()
}

main()