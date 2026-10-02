class State {
    func transition(event: String) -> State {
        return self
    }
}

class ClosedState: State {
    override func transition(event: String) -> State {
        if event == "open" {
            return OpenState()
        }
        return self
    }
}

class OpenState: State {
    override func transition(event: String) -> State {
        if event == "close" {
            return ClosedState()
        }
        if event == "data" {
            return DataState()
        }
        return self
    }
}

class DataState: State {
    override func transition(event: String) -> State {
        if event == "close" {
            return ClosedState()
        }
        if event == "data" {
            return self
        }
        return OpenState()
    }
}

func eventGenerator() -> AnyIterator<String> {
    var states = ["open", "data", "close"]
    return AnyIterator {
        defer { states = Array(states.dropFirst()) + [states.first!] }
        return states.first
    }
}

func stateMachine() {
    var currentState = ClosedState()
    let eventIterator = eventGenerator()
    while let event = eventIterator.next() {
        currentState = currentState.transition(event: event)
    }
}

func main() {
    stateMachine()
}

main()