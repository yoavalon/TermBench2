class NetworkState {
    var state: String

    init() {
        self.state = "init"
    }

    func transition(event: String) {
        if self.state == "init" && event == "connect" {
            self.state = "connected"
        } else if self.state == "connected" && event == "disconnect" {
            self.state = "disconnected"
        } else if self.state == "disconnected" && event == "reconnect" {
            self.state = "connected"
        }
    }
}

class EventProcessor {
    var state_machine: NetworkState
    var events: [String]

    init(state_machine: NetworkState) {
        self.state_machine = state_machine
        self.events = []
    }

    func add_event(event: String) {
        self.events.append(event)
    }

    func process_events() {
        for event in self.events {
            self.state_machine.transition(event: event)
        }
        self.events = []
    }
}

func main() {
    let state_machine = NetworkState()
    let processor = EventProcessor(state_machine: state_machine)
    processor.add_event(event: "connect")
    processor.process_events()
    processor.add_event(event: "disconnect")
    processor.process_events()
    processor.add_event(event: "reconnect")
    processor.process_events()
    print(state_machine.state)
}

main()