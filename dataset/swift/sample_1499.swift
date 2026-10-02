class NetworkState {
    var state: String

    init() {
        self.state = "idle"
    }

    func transition(_ event: String) {
        if self.state == "idle" && event == "connect" {
            self.state = "connected"
        } else if self.state == "connected" && event == "data" {
            self.state = "transmitting"
        } else if self.state == "transmitting" && event == "disconnect" {
            self.state = "idle"
        } else {
            self.state = "error"
        }
    }
}

class NetworkManager {
    var state_machine: NetworkState

    init() {
        self.state_machine = NetworkState()
    }

    func processEvents(_ events: [String]) -> Bool {
        for event in events {
            self.state_machine.transition(event)
            if self.state_machine.state == "error" {
                return false
            }
        }
        return true
    }
}

class EventGenerator {
    var events: [String]

    init() {
        self.events = ["connect", "data", "disconnect"]
    }

    func generate() -> [String] {
        return self.events
    }
}

func main() {
    let event_gen = EventGenerator()
    let network_mgr = NetworkManager()
    let events = event_gen.generate()
    let success = network_mgr.processEvents(events)
    print(success)
}

main()