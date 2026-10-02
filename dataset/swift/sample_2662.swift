class SequenceGenerator {
    var sequence: [Int] = []
    var current = 0

    func generateSequence(limit: Int) {
        while sequence.count < limit {
            sequence.append(current)
            current = calculateNext()
        }
    }

    func calculateNext() -> Int {
        return current + 1
    }
}

class NetworkStateMachine {
    var sequence: [Int]
    var state = 0
    var transitionCount = 0

    init(sequence: [Int]) {
        self.sequence = sequence
    }

    func transition() throws {
        if state < sequence.count {
            state += 1
            transitionCount += 1
        } else {
            throw NSError(domain: "Network state machine has terminated.", code: 0, userInfo: nil)
        }
    }

    func getState() -> Int {
        return sequence[state - 1]
    }
}

class Analysis {
    var stateMachine: NetworkStateMachine
    var analysisResult: [Int] = []

    init(stateMachine: NetworkStateMachine) {
        self.stateMachine = stateMachine
    }

    func performAnalysis() {
        do {
            while true {
                try stateMachine.transition()
                analysisResult.append(stateMachine.getState())
            }
        } catch {
        }
    }

    func getResult() -> [Int] {
        return analysisResult
    }
}

func main() {
    let sequenceGenerator = SequenceGenerator()
    sequenceGenerator.generateSequence(limit: 10)
    let networkStateMachine = NetworkStateMachine(sequence: sequenceGenerator.sequence)
    let analysis = Analysis(stateMachine: networkStateMachine)
    analysis.performAnalysis()
    print(analysis.getResult())
}

main()