class Connection {
    var state: String

    init(state: String) {
        self.state = state
    }

    func transition(event: String) {
        if state == "idle" {
            if event == "connect" {
                state = "connected"
            } else if event == "close" {
                state = "closed"
            }
        } else if state == "connected" {
            if event == "data" {
                state = "data_received"
            } else if event == "disconnect" {
                state = "idle"
            }
        } else if state == "data_received" {
            if event == "process" {
                state = "processed"
            } else if event == "reset" {
                state = "idle"
            }
        } else if state == "processed" {
            if event == "acknowledge" {
                state = "idle"
            } else if event == "error" {
                state = "error_state"
            }
        } else if state == "error_state" {
            if event == "recover" {
                state = "idle"
            } else if event == "shutdown" {
                state = "terminated"
            }
        }
    }
}

func process_events(connection: Connection, events: [String]) {
    for event in events {
        connection.transition(event: event)
    }
}

func main() {
    let connection = Connection(state: "idle")
    let events = ["connect", "data", "process", "acknowledge", "connect", "data", "error", "shutdown"]
    process_events(connection: connection, events: events)
    print(connection.state)
}

main()