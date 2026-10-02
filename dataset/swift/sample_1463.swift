class StateMachine {
    var state: String
    var connection: Bool?

    init() {
        self.state = "idle"
        self.connection = nil
    }

    func transition(event: String) {
        if state == "idle" && event == "connect" {
            state = "connected"
            connection = true
        } else if state == "connected" && event == "disconnect" {
            state = "idle"
            connection = false
        } else if state == "connected" && event == "error" {
            state = "error"
            connection = false
        } else if state == "error" && event == "recover" {
            state = "connected"
            connection = true
        }
    }

    func getStatus() -> (String, Bool?) {
        return (state, connection)
    }
}

func simulateEvents(events: [String]) -> [(String, Bool?)] {
    let machine = StateMachine()
    var statuses: [(String, Bool?)] = []
    for event in events {
        machine.transition(event: event)
        statuses.append(machine.getStatus())
    }
    return statuses
}

func main() {
    let eventsSequence = ["connect", "data", "disconnect", "connect", "error", "recover"]
    let results = simulateEvents(events: eventsSequence)
    for status in results {
        print(status)
    }
}

main()