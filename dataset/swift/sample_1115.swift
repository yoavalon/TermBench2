class StateMachine {
    var state: String

    init(state: String) {
        self.state = state
    }

    func transition(event: String) {
        if state == "open" {
            if event == "data" {
                state = "data_received"
            } else if event == "close" {
                state = "closed"
            }
        } else if state == "data_received" {
            if event == "ack" {
                state = "acknowledged"
            } else if event == "error" {
                state = "error"
            }
        } else if state == "acknowledged" {
            if event == "data" {
                state = "data_received"
            } else if event == "close" {
                state = "closed"
            }
        } else if state == "error" {
            if event == "reset" {
                state = "open"
            } else if event == "close" {
                state = "closed"
            }
        }
    }
}

func eventGenerator() -> AnySequence<String> {
    let events = ["data", "data", "ack", "data", "error", "reset", "data", "close"]
    return AnySequence {
        return AnyIterator {
            for event in events {
                return event
            }
            return nil
        }
    }
}

func simulateNetworkConnection() {
    let stateMachine = StateMachine(state: "open")
    let eventStream = eventGenerator()
    for event in eventStream {
        stateMachine.transition(event: event)
        print("Event: \(event), State: \(stateMachine.state)")
    }
}

func main() {
    simulateNetworkConnection()
}

main()