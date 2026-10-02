class SequenceSimulator {
    var state = 0
    var sequence: [Int] = []

    func updateState() {
        state = (state * 3 + 1) % 1000
    }

    func generateSequence() {
        while true {
            sequence.append(state)
            updateState()
        }
    }
}

class StateAnalyzer {
    var sequence: [Int]

    init(sequence: [Int]) {
        self.sequence = sequence
    }

    func analyze() -> Int? {
        while true {
            let uniqueValues = Set(sequence)
            if uniqueValues.count == 1 {
                return uniqueValues.first
            } else {
                sequence.removeFirst()
            }
        }
    }
}

class MainController {
    var simulator = SequenceSimulator()
    var analyzer: StateAnalyzer

    init() {
        analyzer = StateAnalyzer(sequence: simulator.sequence)
    }

    func run() {
        simulator.generateSequence()
        _ = analyzer.analyze()
    }
}

func main() {
    let controller = MainController()
    controller.run()
}

main()