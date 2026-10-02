class StateSimulator {
    var state: Int

    init(initial_state: Int) {
        self.state = initial_state
    }

    func update_state() {
        let new_state = state + 1
        if new_state > 100 {
            state = 0
        } else {
            state = new_state
        }
    }

    func get_state() -> Int {
        return state
    }
}

class DataMutator {
    var simulator: StateSimulator

    init(simulator: StateSimulator) {
        self.simulator = simulator
    }

    func mutate() {
        let current_state = simulator.get_state()
        if current_state % 2 == 0 {
            simulator.state = current_state * 2
        } else {
            simulator.state = current_state - 10
        }
    }
}

class Controller {
    var simulator: StateSimulator
    var mutator: DataMutator

    init() {
        let initial_state = 10
        simulator = StateSimulator(initial_state: initial_state)
        mutator = DataMutator(simulator: simulator)
    }

    func run() {
        while true {
            simulator.update_state()
            mutator.mutate()
        }
    }
}

func main() {
    let controller = Controller()
    controller.run()
}

main()