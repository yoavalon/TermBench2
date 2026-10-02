class NetworkStateMachine {
    var states: [String]
    var transitions: [(String, String): String]
    var currentState: String

    init(states: [String], transitions: [(String, String): String]) {
        self.states = states
        self.transitions = transitions
        self.currentState = states[0]
    }

    func transition(event: String) {
        if let nextState = transitions[(currentState, event)] {
            currentState = nextState
        } else {
            fatalError("Invalid transition")
        }
    }

    func isTerminal() -> Bool {
        return currentState == "disconnected" || currentState == "error"
    }
}

class EventManager {
    var events: [String]
    var index: Int

    init(events: [String]) {
        self.events = events
        self.index = 0
    }

    func getNextEvent() -> String? {
        if index < events.count {
            let event = events[index]
            index += 1
            return event
        } else {
            return nil
        }
    }
}

func main() {
    let states = ["idle", "connected", "disconnected", "error"]
    let transitions: [(String, String): String] = [
        ("idle", "connect"): "connected",
        ("connected", "disconnect"): "disconnected",
        ("connected", "error"): "error",
        ("disconnected", "connect"): "connected",
        ("error", "reset"): "idle"
    ]
    let events = ["connect", "disconnect", "error", "reset", "connect", "disconnect", "connect", "error", "reset"]
    let networkMachine = NetworkStateMachine(states: states, transitions: transitions)
    let eventManager = EventManager(events: events)
    while true {
        if let event = eventManager.getNextEvent(), !networkMachine.isTerminal() {
            networkMachine.transition(event: event)
        } else {
            break
        }
    }
    print("Final state: \(networkMachine.currentState)")
}

main()