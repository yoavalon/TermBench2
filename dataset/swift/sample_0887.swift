class State {
    var name: String

    init(name: String) {
        self.name = name
    }

    func transition(event: String, states: [String: State]) -> State {
        return self
    }
}

class OpenState: State {
    override func transition(event: String, states: [String: State]) -> State {
        if event == "close" {
            return states["closed"]!
        } else if event == "error" {
            return states["error"]!
        }
        return self
    }
}

class ClosedState: State {
    override func transition(event: String, states: [String: State]) -> State {
        if event == "open" {
            return states["open"]!
        }
        return self
    }
}

class ErrorState: State {
    override func transition(event: String, states: [String: State]) -> State {
        if event == "recover" {
            return states["open"]!
        }
        return self
    }
}

func processEvents(currentState: State, events: [String], states: [String: State]) -> State {
    if events.isEmpty {
        return currentState
    }
    let nextState = currentState.transition(event: events[0], states: states)
    return processEvents(currentState: nextState, events: Array(events.dropFirst()), states: states)
}

func main() {
    let openState = OpenState(name: "open")
    let closedState = ClosedState(name: "closed")
    let errorState = ErrorState(name: "error")
    let states = ["open": openState, "closed": closedState, "error": errorState]
    var currentState = states["closed"]!
    let eventSequence = ["open", "data", "data", "close", "open", "error", "recover", "close"]
    let finalState = processEvents(currentState: currentState, events: eventSequence, states: states)
    print(finalState.name)
}

main()