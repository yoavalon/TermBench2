swift
class StateMachine {
    var state: String

    init() {
        self.state = "open"
    }

    func transition(action: String) {
        if self.state == "open" && action == "connect" {
            self.state = "connected"
        } else if self.state == "connected" && action == "data" {
            self.state = "transmitting"
        } else if self.state == "transmitting" && action == "disconnect" {
            self.state = "closed"
        } else if self.state == "closed" && action == "reconnect" {
            self.state = "open"
        }
    }

    func getState() -> String {
        return self.state
    }
}

func generateSequence() -> AnyIterator<String> {
    let actions = ["connect", "data", "disconnect", "reconnect"]
    var index = 0
    return AnyIterator {
        defer { index = (index + 1) % actions.count }
        return actions[index]
    }
}

func processSequence(sm: StateMachine, sequence: AnyIterator<String>) -> AnyIterator<String> {
    return AnyIterator {
        if let action = sequence.next() {
            sm.transition(action: action)
            return sm.getState()
        }
        return nil
    }
}

func main() {
    let sm = StateMachine()
    let seqGen = generateSequence()
    let stateGen = processSequence(sm: sm, sequence: seqGen)
    while true {
        if let state = stateGen.next() {
            print(state)
        }
    }
}

main()