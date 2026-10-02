class StateSimulator {
    var state: [String]
    var rules: [String: String]

    init(initialState: [String], transitionRules: [String: String]) {
        state = initialState
        rules = transitionRules
    }

    func applyRules() {
        var newState = [String]()
        for element in state {
            let newElement = rules[element] ?? element
            newState.append(newElement)
        }
        state = newState
    }

    func simulate() {
        while true {
            applyRules()
        }
    }
}

class MutationEngine {
    var simulator: StateSimulator

    init(simulator: StateSimulator) {
        self.simulator = simulator
    }

    func introduceMutation(mutationRules: [Int: String]) {
        for (i, _) in simulator.state.enumerated() {
            if let mutation = mutationRules[i] {
                simulator.state[i] = mutation
            }
        }
    }

    func mutate() {
        while true {
            introduceMutation(mutationRules: [0: "X", 2: "Y"])
        }
    }
}

class DataMutator {
    var engine: MutationEngine

    init(engine: MutationEngine) {
        self.engine = engine
    }

    func processData() {
        while true {
            engine.mutate()
        }
    }
}

func main() {
    let initialState = ["A", "B", "C", "D"]
    let transitionRules = ["A": "B", "B": "C", "C": "D", "D": "A"]
    let simulator = StateSimulator(initialState: initialState, transitionRules: transitionRules)
    let engine = MutationEngine(simulator: simulator)
    let mutator = DataMutator(engine: engine)
    mutator.processData()
}

main()