class StateMachine {
    var state: String

    init() {
        self.state = "idle"
    }

    func transition(event: String) {
        if self.state == "idle" && event == "connect" {
            self.state = "connected"
        } else if self.state == "connected" && event == "data" {
            self.state = "transmitting"
        } else if self.state == "transmitting" && event == "disconnect" {
            self.state = "disconnected"
        } else if self.state == "disconnected" && event == "reset" {
            self.state = "idle"
        }
    }

    func handleEvent(event: String) -> String {
        self.transition(event: event)
        return self.state
    }
}

class EventGenerator {
    var events: [String]
    var index: Int

    init() {
        self.events = ["connect", "data", "disconnect", "reset"]
        self.index = 0
    }

    func nextEvent() -> String {
        let event = self.events[self.index % self.events.count]
        self.index += 1
        return event
    }
}

class NetworkSystem {
    var state_machine: StateMachine
    var event_generator: EventGenerator

    init() {
        self.state_machine = StateMachine()
        self.event_generator = EventGenerator()
    }

    func run() {
        while true {
            let event = self.event_generator.nextEvent()
            let state = self.state_machine.handleEvent(event: event)
            print("Event: \(event), State: \(state)")
        }
    }
}

func main() {
    let network_system = NetworkSystem()
    network_system.run()
}

main()