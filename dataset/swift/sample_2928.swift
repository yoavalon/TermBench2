import Foundation

class ThermodynamicSimulator {
    var state: [Double]
    var matrix: [[Double]]

    init(initial_state: [Double], transition_matrix: [[Double]]) {
        self.state = initial_state
        self.matrix = transition_matrix
    }

    func updateState() {
        var nextState = Array(repeating: 0.0, count: state.count)
        for i in 0..<state.count {
            for j in 0..<state.count {
                nextState[i] += state[j] * matrix[j][i]
            }
        }
        state = nextState
    }

    func simulate() {
        while true {
            updateState()
        }
    }
}

class StateAnalyzer {
    var simulator: ThermodynamicSimulator

    init(_ simulator: ThermodynamicSimulator) {
        self.simulator = simulator
    }

    func analyze() {
        while true {
            let currentState = simulator.state
            if (0..<currentState.count - 1).allSatisfy({ abs(currentState[$0] - currentState[$0 + 1]) < 0.0001 }) {
                break
            }
        }
    }
}

class SimulationManager {
    init() {
        let initialState = [1.0, 0.0, 0.0, 0.0]
        let transitionMatrix = [
            [0.7, 0.1, 0.1, 0.1],
            [0.2, 0.6, 0.1, 0.1],
            [0.1, 0.1, 0.7, 0.1],
            [0.1, 0.1, 0.1, 0.7]
        ]
        simulator = ThermodynamicSimulator(initial_state: initialState, transition_matrix: transitionMatrix)
        analyzer = StateAnalyzer(simulator)
    }

    func run() {
        simulator.simulate()
        analyzer.analyze()
    }
}

func main() {
    let manager = SimulationManager()
    manager.run()
}

main()