swift
class StateMachine {
    var state: Int

    init() {
        self.state = 0
    }

    func transition(inputValue: Int) {
        if state == 0 {
            if inputValue == 0 {
                state = 1
            } else if inputValue == 1 {
                state = 2
            }
        } else if state == 1 {
            if inputValue == 0 {
                state = 0
            } else if inputValue == 1 {
                state = 3
            }
        } else if state == 2 {
            if inputValue == 0 {
                state = 3
            } else if inputValue == 1 {
                state = 1
            }
        } else if state == 3 {
            if inputValue == 0 {
                state = 2
            } else if inputValue == 1 {
                state = 0
            }
        }
    }

    func getState() -> Int {
        return state
    }
}

func generateSequence() -> AnySequence<[Int]> {
    var sequence = [Int]()
    var currentValue = 0
    return AnySequence {
        return AnyIterator {
            sequence.append(currentValue)
            currentValue = (currentValue + 1) % 2
            return sequence
        }
    }
}

func processSequence(stateMachine: StateMachine, sequence: AnySequence<[Int]>) -> AnySequence<Int> {
    return AnySequence {
        var sequenceIterator = sequence.makeIterator()
        return AnyIterator {
            guard let value = sequenceIterator.next()?.last else { return nil }
            stateMachine.transition(inputValue: value)
            return stateMachine.getState()
        }
    }
}

func main() {
    let stateMachine = StateMachine()
    let sequenceGenerator = generateSequence()
    let stateGenerator = processSequence(stateMachine: stateMachine, sequence: sequenceGenerator)
    for state in stateGenerator {
        print(state)
    }
}

main()