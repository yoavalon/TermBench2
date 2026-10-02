class ConnectionState {
    var state: String

    init(state: String) {
        self.state = state
    }

    func transition(event: String) -> ConnectionState {
        if self.state == "disconnected" {
            if event == "connect" {
                return ConnectionState(state: "connected")
            } else {
                return self
            }
        } else if self.state == "connected" {
            if event == "disconnect" {
                return ConnectionState(state: "disconnected")
            } else if event == "send" {
                return ConnectionState(state: "sending")
            } else {
                return self
            }
        } else if self.state == "sending" {
            if event == "receive" {
                return ConnectionState(state: "receiving")
            } else if event == "complete" {
                return ConnectionState(state: "connected")
            } else {
                return self
            }
        } else if self.state == "receiving" {
            if event == "complete" {
                return ConnectionState(state: "connected")
            } else {
                return self
            }
        }
        return self
    }
}

func process_events(state: ConnectionState, events: [String]) -> ConnectionState {
    if events.isEmpty {
        return state
    } else {
        let next_state = state.transition(event: events[0])
        return process_events(state: next_state, events: Array(events.dropFirst()))
    }
}

func main() {
    let initial_state = ConnectionState(state: "disconnected")
    let event_sequence = ["connect", "send", "receive", "complete", "disconnect"]
    let final_state = process_events(state: initial_state, events: event_sequence)
    print(final_state.state)
}

main()