class ConnectionState {
    var state: String

    init() {
        state = "DISCONNECTED"
    }

    func transition(event: String) {
        if state == "DISCONNECTED" && event == "CONNECT" {
            state = "CONNECTED"
        } else if state == "CONNECTED" && event == "DATA" {
            state = "ACTIVE"
        } else if state == "ACTIVE" && event == "DISCONNECT" {
            state = "DISCONNECTED"
        } else if state == "DISCONNECTED" && event == "ERROR" {
            state = "ERROR"
        }
    }
}

class EventGenerator {
    let events: [String]

    init() {
        events = ["CONNECT", "DATA", "DISCONNECT", "ERROR"]
    }

    func generate() -> AnyIterator<String> {
        return AnyIterator {
            for event in self.events {
                return event
            }
            return nil
        }
    }
}

class NetworkAnalyzer {
    let connection: ConnectionState
    let events: EventGenerator

    init() {
        connection = ConnectionState()
        events = EventGenerator()
    }

    func analyze() {
        for event in events.generate() {
            connection.transition(event: event)
            if connection.state == "ERROR" {
                print("Error encountered, resetting state.")
                connection.state = "DISCONNECTED"
            }
        }
    }
}

func main() {
    let analyzer = NetworkAnalyzer()
    analyzer.analyze()
}

main()