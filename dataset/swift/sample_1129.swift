class NetworkState {
    var state: String

    init(state: String) {
        self.state = state
    }

    func transition(event: String) -> String {
        if state == "DISCONNECTED" && event == "CONNECT" {
            return "CONNECTED"
        } else if state == "CONNECTED" && event == "DISCONNECT" {
            return "DISCONNECTED"
        } else if state == "CONNECTED" && event == "RECEIVE" {
            return "PROCESSING"
        } else if state == "PROCESSING" && event == "SEND" {
            return "CONNECTED"
        } else {
            return state
        }
    }
}

class NetworkStateMachine {
    var currentState: NetworkState

    init() {
        currentState = NetworkState(state: "DISCONNECTED")
    }

    func processEvent(event: String) -> String {
        let newState = currentState.transition(event: event)
        currentState = NetworkState(state: newState)
        return newState
    }
}

func generateEvents() -> [String] {
    let events = ["CONNECT", "RECEIVE", "SEND", "DISCONNECT"]
    return Array(repeating: events, count: 10).flatMap { $0 }
}

func simulateNetwork() {
    let stateMachine = NetworkStateMachine()
    let events = generateEvents()
    var index = 0
    while true {
        let event = events[index % events.count]
        let newState = stateMachine.processEvent(event: event)
        index += 1
        if newState == "PROCESSING" {
            simulateNetwork()
        }
    }
}

func main() {
    simulateNetwork()
}

main()