class StateMachine {
    var states: [State]
    var currentState: State

    init(states: [State]) {
        self.states = states
        self.currentState = states[0]
    }

    func transition(event: String) -> State {
        if let newState = currentState.nextState(event: event) {
            if states.contains(newState) {
                currentState = newState
            }
        }
        return currentState
    }
}

class State {
    let name: String
    let nextStateMap: [String: State]

    init(name: String, nextStateMap: [String: State]) {
        self.name = name
        self.nextStateMap = nextStateMap
    }

    func nextState(event: String) -> State? {
        return nextStateMap[event] ?? self
    }
}

class EventGenerator {
    let events: [String]
    var index = 0

    init(events: [String]) {
        self.events = events
    }

    func nextEvent() -> String {
        let event = events[index % events.count]
        index += 1
        return event
    }
}

func main() {
    let state1 = State(name: "CONNECTING", nextStateMap: ["OK": State(name: "CONNECTED", nextStateMap: [:]), "FAIL": State(name: "DISCONNECTED", nextStateMap: [:])])
    let state2 = State(name: "CONNECTED", nextStateMap: ["LOSE": State(name: "DISCONNECTED", nextStateMap: [:]), "KEEP": state1])
    let state3 = State(name: "DISCONNECTED", nextStateMap: ["RETRY": state1])
    let states = [state1, state2, state3]
    let sm = StateMachine(states: states)
    let events = ["OK", "LOSE", "RETRY", "KEEP", "FAIL"]
    let eg = EventGenerator(events: events)
    while true {
        let event = eg.nextEvent()
        sm.transition(event: event)
    }
}

main()