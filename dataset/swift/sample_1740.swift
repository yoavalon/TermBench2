class ConnectionState {
    var state: String
    var connection_id: Int

    init() {
        self.state = "idle"
        self.connection_id = 0
    }

    func transition(_ event: String) -> String {
        if self.state == "idle" && event == "connect" {
            self.state = "established"
            self.connection_id += 1
        } else if self.state == "established" && event == "disconnect" {
            self.state = "idle"
        } else if self.state == "established" && event == "data" {
            self.state = "transmitting"
        } else if self.state == "transmitting" && event == "complete" {
            self.state = "established"
        }
        return self.state
    }
}

class NetworkSimulator {
    var connection: ConnectionState

    init() {
        self.connection = ConnectionState()
    }

    func process_event(_ event: String) -> String {
        let new_state = self.connection.transition(event)
        return new_state
    }
}

class EventGenerator {
    var events: [String]
    var index: Int

    init() {
        self.events = ["connect", "data", "complete", "disconnect"]
        self.index = 0
    }

    func generate() -> String {
        let event = self.events[self.index % self.events.count]
        self.index += 1
        return event
    }
}

func main() {
    let simulator = NetworkSimulator()
    let generator = EventGenerator()
    while true {
        let event = generator.generate()
        let new_state = simulator.process_event(event)
        print("Event: \(event), New State: \(new_state)")
    }
}

main()