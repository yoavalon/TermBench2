class ConnectionState {
    var state: String

    init() {
        self.state = "DISCONNECTED"
    }

    func transition(_ event: String) {
        if state == "DISCONNECTED" && event == "CONNECT" {
            state = "CONNECTED"
        } else if state == "CONNECTED" && event == "DATA" {
            state = "DATA_RECEIVED"
        } else if state == "DATA_RECEIVED" && event == "ACKNOWLEDGE" {
            state = "ACKNOWLEDGED"
        } else if state == "ACKNOWLEDGED" && event == "DISCONNECT" {
            state = "DISCONNECTED"
        }
    }
}

class EventGenerator {
    func generate_events() -> AnyIterator<String> {
        return AnyIterator {
            return "CONNECT"
        }
    }
}

class NetworkAnalyzer {
    let connection: ConnectionState
    let event_gen: EventGenerator

    init() {
        self.connection = ConnectionState()
        self.event_gen = EventGenerator()
    }

    func analyze() {
        for event in event_gen.generate_events() {
            self.connection.transition(event)
            print("Current state: \(self.connection.state)")
        }
    }
}

func main() {
    let analyzer = NetworkAnalyzer()
    analyzer.analyze()
}

main()